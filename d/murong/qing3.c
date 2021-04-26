// Code of ShenZhou
// Room: /d/murong/qing3
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "�쾮");
	set("long", @LONG
    ����һ��������쾮����������һ���СС����ש(zhuan)��������һ�䲻���Ů�ң����������ң������Ǹ������ʹŮ�����;�ס�ġ�������һ�����������ƺ�����������ˡ�
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "south" : __DIR__"qing2",
        "north" : __DIR__"qing4",
        "west" : __DIR__"chufang",
        "east" : __DIR__"kufang",
                      ]));

	set("no_clean_up", 0);
        set("outdoors", "murong");

        set("objects", ([
		"/d/murong/npc/shinu" : 3,
		]));

	setup();
	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        if (dir=="east" || dir=="west") {
                if (dir=="west" && me->query("family/family_name")=="����Ľ��")
                        return notify_fail("��Ľ���ϵ��Ӳ��ܽ�ȥ��\n");
                if (dir=="east" && me->query("family/family_name")=="����Ľ��")
                        return notify_fail("��Ľ���ϵ��Ӳ��ܽ�ȥ��\n");
        }
        return ::valid_leave(me, dir);
}
