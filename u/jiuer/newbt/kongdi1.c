// Code of ShenZhou
// jiuer
// d/baituo/kongdi1.c

inherit ROOM;

void create()
{
	set("short", "�յ�");
	set("long", @LONG
����һ��Ƭ�ǳ�ƽ����ɳʯ�յأ�����ϡϡ�����س���Щ���ֲ����
������Щ���СС�ĺ�ɫʯ�Ӻͺ�ɫ�ĸ�Ӳ���飬������ͨ��ɽׯ��ǰԺ
����Ʈ������Ʋ����������Ϻ������������ϸ���һ��С��ͨ�����ҡ�
LONG
	);
	set("exits", ([ 
	    "northwest" : __DIR__"road2",
		"southwest" : __DIR__"barn4a",
		"southeast" :__DIR__"barn5a",
	]));
	create_door("southeast", "ľ��", "northwest");
	create_door("southwest", "����", "northeast");

	set("outdoors","baituo");
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
    if (dir == "southeast" || dir == "southwest") 
	{
		if (me->query("family/family_name")!="����ɽ")
		{ 
			return notify_fail("���Ҷ���̫�أ��㻹�ǲ�Ҫ��ȥΪ�ã�\n");
		}
    }
    return ::valid_leave(me,dir);
}
