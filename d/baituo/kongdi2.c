// Code of ShenZhou
// jiuer
// d/baituo/kongdi2.c

inherit ROOM;

void create()
{
	set("short", "�յ�");
	set("long", @LONG
����һ��Ƭ�ǳ�ƽ����ɳʯ�յأ�����ϡϡ�����س���Щ���ֲ����
������Щ���СС�ĺ�ɫʯ�Ӻͺ�ɫ�ĸ�Ӳ���飬����ͨ��ɽׯ�ĺ�Ժ��
����ǰ�߾��ǰ���ɽׯ��ѵ�߳��͹��߷���
LONG
	);
	set("exits", ([ 
	    "north" : __DIR__"houyuan",
		"southeast" : __DIR__"toolroom",
		"southwest" :__DIR__"trainroom",
	]));

	set("outdoors","baituo");
	replace_program(ROOM);
	set("cost", 1);
	setup();
}
