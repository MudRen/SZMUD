// Filename:   /d/jueqinggu/changlang1.c ����1
// Code:       Jiuer
// Date:       Aug 15, 2001


inherit ROOM;

void create()
{
		  set("short","����");
		  set("long",@LONG
����һ�����������ȣ�ǽ�ڶ��������ߺ����ʯ���������ɡ��ϱ�
ǽ�Ͼ��ȵ���Ƕ��һЩС��������ڷ���һЩ��յ���ѳ����յ�������
�ġ����ȱ����Ǵ��������治Զ���Ǹ���ˮ����
LONG);
		  set("exits",([ 
			  "out" : __DIR__"shiwu",
			  "north" : __DIR__"dating",
			  ]));

	  set("cost",1);
	  setup();	
	  replace_program(ROOM);
}