// Code of ShenZhou
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ�����������ĳ��ȣ�����һ����һ���ſ���ת���֣���һ��
˳�����һ�����͵ơ���Ƶĵƹ���Ӱ����ҡ߮��������ů��������
��������������Ѳ��������������ͣ��������߾��Ǵ���ˡ�
LONG
        );
        set("exits", ([
                "north" : __DIR__"dadian",
				"south" : __DIR__"dumudian",
        ]));

        set("objects", ([
                __DIR__"npc/jlseng" : 2,
        ]));

        set("cost", 1);
        setup();
}

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

   if (dir =="north" ) {

        if (present("jielv seng", environment(me))) {
            if (!myfam || myfam["family_name"] != "ѩɽ��"
            && myfam["family_name"] != "Ѫ����" )
                return notify_fail("����ɮ��ס��˵�������˱����صأ���ذɣ�\n");
        }
   }
   if (dir =="south" ) {
        if (present("jielv seng", environment(me))) {
			if (present("juan na xiang", this_player())) {
                 if (myfam["family_name"] == "ѩɽ��" ||
                     myfam["family_name"] == "Ѫ����") 
                        return notify_fail("����ɮ��ס��˵����Ϊ���ŵ��ӣ������þ����䣬������Ż�ȥ��\n");
				 else
                        return notify_fail("����ɮ�ٺٸ�Ц������˵�����������Ƿ�ү�ı��������ߣ�\n");
			}
		}
   }
   return ::valid_leave(me, dir);
}

