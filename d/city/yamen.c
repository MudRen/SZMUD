// Code of ShenZhou
// Room: /city/yamen.c
// modified by aln  2 / 98

#define BANGZHU "/d/huanghe/npc/bangzhu"

#include <ansi.h>
inherit ROOM;

#include "/d/REGIONS.h"

string look_gaoshi();

void create()
{
	set("short", RED"����"NOR);
	set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ������ӷַ�
��ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ�������������ǰ
Ѳ�ߡ����ű�����һ�Ű����ʾ(gaoshi)��
LONG
	);

        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

	set("exits", ([
		"north" : __DIR__"xidajie2",
		"south" : __DIR__"ymzhengting",
	]));

	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));

	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && !me->query_temp("mark/Ѳ��") && dir == "south" 
	&& objectp(present("ya yi", environment(me))) )
		return notify_fail("���ۺȵ������������䡭������\n");
	return ::valid_leave(me, dir);
}

string look_gaoshi()
{
        object *obj, room;
        string file, region, str = "";

        obj = filter_array(children(BANGZHU), (: clonep :));     
        if( sizeof(obj) ) {
                for(int i = 0; i < sizeof(obj); i++) {
                if( room = environment(obj[i]) ) {
                file = base_name(room);
                if( strsrch(file, "/d/") == 0 && mapp(room->query("exits")) ) {
                region = explode(file, "/")[1];
                str += obj[i]->query("fam") + "  " + "���������û��" + region_names[region] + room->query("short") + "��\n";
                }
		}
	        }
	}

        if( str == "" )
                str += "������ɻ������\n";

        str += "\n�㽭�ᶽ\n�����\n";
	return str;
}
