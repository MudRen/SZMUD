// July 31,2000
// Code by April
// /gumu/dating.c
// Update April 01.08.24

inherit ROOM;

void create()
{
	set("short","����");

	set("long",@LONG
���������õļ�Ϊ�򵥣�����ľ�κͼ������ӷ��������У���ǽ��
һ��С�����ϵ���һֻС������¯��Ʈ�������������̴���һ����ζ����
ζ��Ũ�����壬������һ��ƮƮȻ�ĸо������е����ϲ��˼�֦���򣬰�
�����յ����λεġ�
LONG);

	set("exits",([ 
		"west" : __DIR__"mudao15",
		"south" : __DIR__"mudao1",
		"east" : __DIR__"mudao2",
		"north" : __DIR__"mudao14",
		]) );
	
	set("cost",1);
    set("no_fight",1);
      set("valid_startroom", 1);

    set("objects",([
      ]));

	setup();
	 "/clone/board/gumu_b"->foo();
}
