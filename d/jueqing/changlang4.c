// Filename:   /d/jueqinggu/changlang4.c ����4
// Code:       Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","����");
		  set("long",@LONG
����һ�����������ȣ�ǽ�ڶ��������ߺ����ʯ���������ɡ��ϱ�
ǽ�Ͼ��ȵ���Ƕ��һЩС��������ڷ���һЩ��յ���ѳ����յ�������
�ġ����ȱ����Ǽ��鷿�������Ǻ��á�
LONG);
		  set("exits",([ 
		      "east" : __DIR__"houtang",
			  "west" : __DIR__"changlang3",
			  "north" : __DIR__"shufang",
			 ]));
		  
		  create_door("north", "ľ��", "south");
		  set("cost",1);
		  setup();	
		  replace_program(ROOM);
}