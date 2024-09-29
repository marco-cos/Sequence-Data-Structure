//Author Name: Marco Coscoy
//UID: 705960849

#include "Sequence.h"

Sequence::Sequence() {
	head.forward = &tail;
	head.back = NULL;

	tail.forward = NULL;
	tail.back = &head;

	m_size = 0;
}

bool Sequence::empty() const {
	if (m_size == 0) {
		return true;
	}
	else {
		return false;
	}
}

int Sequence::size() const{
	return m_size;
}

int Sequence::insert(int pos, const ItemType& value) {

	//Add to end of list
	if (pos == m_size) {
		Node* np3 = new Node;
		Node* tempold = tail.back;
		tempold->forward = np3;
		np3->back = tempold;
		np3->forward = &tail;
		tail.back = np3;
		np3->value = value;
		m_size++;
		return pos;
	}

	//Regular insertions into list with multiple elements
	int c = 0;
	for (Node* p = &head; p != NULL; p = p->forward) {
		if (p != &head) {
			if (c == pos) { //Found item at position pos 
				Node* np2 = new Node;
				Node* tempback = p->back;

				np2->forward = p;
				np2->back = tempback;
				tempback->forward = np2;
				p->back = np2;

				np2->value = value;

				m_size++;
				return pos;
			}
			c++;
		}
	}



	return -1;

}

int Sequence::insert(const ItemType& value) {

	int c = 0;
	for (Node* p = &head; p != NULL; p = p->forward) {
		if ((p != &head) && (p != &tail)) {
			if (value <= p->value) { //Check if item is less than or equal to value of that item in list
				Node* np2 = new Node;
				Node* tempback = p->back;

				np2->forward = p;
				np2->back = tempback;
				tempback->forward = np2;
				p->back = np2;

				np2->value = value;

				m_size++;
				return c;
			}
			c++;
		}
	}

	//Add to end of given that no <= values found
	Node* np3 = new Node;
	Node* tempold = tail.back;
	tempold->forward = np3;
	np3->back = tempold;
	np3->forward = &tail;
	tail.back = np3;
	np3->value = value;
	m_size++;
	return c;
}

bool Sequence::erase(int pos) {
	int c = 0;

	for (Node* p = head.forward; p != NULL; p = p->forward) {
		if ((p != &head) && (p != &tail)) {
			if (pos == c) {
				//Change pointers of next and back node to point to each other, then delete p
				Node* forward = p->forward;
				Node* back = p->back;
				delete p;
				
				back->forward = forward;
				forward->back = back;

				m_size--;
				return true;
			}
			c++;
		}
	}

	return false;
}

int Sequence::remove(const ItemType& value) {
	int erasecount = 0;

	//Find where value is, delete at that location using erase function
	for (int b = find(value); b != -1; ) {
		erase(find(value)); 
		//std::cerr << std::endl<< "erasing item at location " << find(b);
		b = find(value);
		erasecount++;
	}

	return erasecount;
}

bool Sequence::get(int pos, ItemType& value) const {
	int currentpos = -1;
	//Checking conditions
	if ((pos < 0) || (pos >= m_size))
		return false;

	//First item in list edge case
	if ((pos == 0) && (m_size > 0)) {
		value = head.forward->value;
		return true;
	}

	Node* p = head.forward;

	for (;p != NULL;) {
		currentpos++;
		if (currentpos == pos) {
			value = p->value;
			return true;
		}
		p = p->forward;
	}

	return false;
	
}

bool Sequence::set(int pos, const ItemType& value) {
	
	if ((pos >= 0) && pos < m_size) {
		insert(pos, value);
		erase(pos + 1);
		return true;
	}
	else
	{
		return false;
	}
}

int Sequence::find(const ItemType& value) const {
	ItemType val;
	for (int i = 0; i < m_size; i++) {
		get(i, val);
		if (val == value) {
			return i;
		}
	}

	return -1;
}

void Sequence::swap(Sequence& other) {
	//Create temp variable that is copy of other
	Sequence temp = other;
	
	//Set other to this class's value, set this class's value to value of temp
	other = *this;
	*this = temp;
}

Sequence::~Sequence(){
	for (Node* p = head.forward->forward; p != NULL;p = p->forward) {
		delete p->back;
	}
}

Sequence::Sequence(const Sequence& old) {
	//Initialize values just like regular constructor
	head.forward = &tail;
	head.back = NULL;

	tail.forward = NULL;
	tail.back = &head;

	m_size = 0;

	//Outsource to insert function for every value, starting at back for proper order
	for (Node* p = old.tail.back->back; p != NULL; p = p->back) {
		insert(0, p->forward->value);
	}


}


Sequence Sequence::operator=(const Sequence& n) {
	for (int i = 0;m_size!=0; i++) {		
		erase(0); //Start from empty list
	}


	//Outsource to insert function for every value, starting at back for proper order
	for (Node* p = n.tail.back->back; p != NULL; p = p->back) {
		insert(0, p->forward->value);
	}

	return *this;
}


void Sequence::dump() const{
	ItemType val;

	for (int i = 0; i < m_size; i++) {
		get(i, val);
		std::cerr << "in element: " << i << " With value of: " << val << std::endl;
	}
}

int subsequence(const Sequence& seq1, const Sequence& seq2) {
	if (seq1.empty() || seq2.empty())
		return -1;

	ItemType seq1_val;
	ItemType seq2_val;


	int matchamount = 0;
	int matchtarget = seq2.size();


	for (int i = 0; i < seq1.size(); i++) {
		//Get new values
		seq1.get(i, seq1_val);
		seq2.get(matchamount, seq2_val);

		//std::cerr << "Match#: " << matchamount << " seq1: " << seq1_val << " seq2: " << seq2_val << std::endl;

		if (seq1_val == seq2_val) {
			matchamount++; //Iterate seq2 getter to next element if match is found
		}
		else {
			matchamount = 0; //Start over match searching if incorrect value encountered
		}

		if (matchamount == matchtarget)
			return i - matchtarget+1;
	}

	return -1;
}

void concatReverse(const Sequence& seq1, const Sequence& seq2, Sequence& result) {
	ItemType val;
	int seq1startsize = seq1.size();
	int seq2startsize = seq2.size();

	//To account for aliasing, values are all temporarily stored in corresponding new sequences (except result, which should be empty)
	Sequence tempseq1 = seq1;
	Sequence tempseq2 = seq2;
	Sequence tempresults;

	//Iterate through seq2, inserting to result along the way
	for (int i = 0; i < seq2startsize; i++) {
		tempseq2.get(i, val);
		tempresults.insert(0, val);
	}

	//Iterate  through seq1, inserting to result along the way
	for (int i = 0; i < seq1startsize; i++) {
		tempseq1.get(i, val);
		tempresults.insert(0,val);
	}
	
	//Swap values back to regular results sequence
	result.swap(tempresults);
}