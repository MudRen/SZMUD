// Filename:   /d/jueqinggu/changlang5.c ����5
// Code:       Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","����");
		  set("long",@LONG
����һ�����������ȣ�ǽ�ڶ��������ߺ����ʯ���������ɡ��ϱ�
ǽ�Ͼ��ȵ���Ƕ��һЩС��������ڷ���һЩ��յ���ѳ����յ�������
�ġ����ȱ���Ʈ��һ�ɷ����㡣
LONG);
		  set("exits",([ 
			  "east" : __DIR__"changlang6",
			  "west" :__DIR__"houtang",
			  "north" : __DIR__"chufang",
			 ]));

	  set("cost",1);
	  setup();	
	  replace_program(ROOM);
}