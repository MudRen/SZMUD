// Filename:   /d/jueqinggu/changlang2.c ����2
// Code:       Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","����");
		  set("long",@LONG
����һ�����������ȣ�ǽ�ڶ��������ߺ����ʯ���������ɡ��ϱ�
ǽ�Ͼ��ȵ���Ƕ��һЩС��������ڷ���һЩ��յ���ѳ����յ�������
�ġ�
LONG);
		  set("exits",([ 
			  "east" : __DIR__"dating",
			  "west" : __DIR__"shishi1",
			  ]));

	  set("cost",1);
	  setup();	
	  replace_program(ROOM);
}