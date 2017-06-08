//segment tree implementation.....
//array sum problem.......



#include<bits/stdc++.h>
using namespace std;

int segment[1000];

void build(int a[],int si,int ei,int start)
{
	if(si==ei)
	   segment[start]=a[si];
	else
	{
		int mid=(si+ei)/2;
		build(a,si,mid,2*start+1);
		build(a,mid+1,ei,2*start+2);
		segment[start]=segment[2*start+1]+segment[2*start+2];
	}
}

int query(int si,int ei,int l,int r,int start)
{
	if(ei<l || si>r)
	   return 0;
	if(si>=l && r>=ei)
	   return segment[start];
	int mid=(si+ei)/2;
	return query(si,mid,l,r,2*start+1)+query(mid+1,ei,l,r,2*start+2);
}

void update(int si,int ei,int l,int start,int value)
{
	if(si>l || ei<l)
	   return;
	if(si==ei)
	   segment[start]=segment[start]+value;
	else
	{
		int mid=(si+ei)/2;
		update(si,mid,l,2*start+1,value);
		update(mid+1,ei,l,2*start+2,value);
		segment[start]=segment[2*start+1]+segment[2*start+2];
	}
}

int main()
{
	int n=8;         //no of elements in array
	int a[]={2,4,1,-1,6,8,3,7};    //array elements 
	build(a,0,n-1,0);   //building the segment tree
	cout<<"sum of elements from 1-4 is: "<<query(0,n-1,1,4,0)<<"\n";    // query for sum from index 1 to 4
	update(0,n-1,1,0,2);   // incrementing the value at index 1 by 2
	update(0,n-1,4,0,10);   // incrementing the value at index 4 by 10
	cout<<"sum of elements from 0-7 is: "<<query(0,n-1,0,7,0)<<"\n";   // query for sum from index 0 to 7
	return 0;
}
