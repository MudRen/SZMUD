// Filename:   /d/jueqinggu/shiwu2.c
// by Jiuer /08/2001


inherit ROOM;

void create()
{
	set("short","ʯ��");
	set("long",@LONG
����һ����С��ʯͷ��������ӡ��ݽǰ���һ����ˮ�ף���������
���Ų�ϯ��
LONG);

	set("exits",([ "out" : __DIR__"shiwu1", ]));

	set("sleep_room",1);
	set("no_fight",1);
	set("resource/water", 1);

	set("cost",1);
	setup();	
}

