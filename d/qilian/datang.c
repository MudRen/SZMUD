// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
�����ڵ���һ����ڻԻ͵Ĵ�������������������µĳ�����
�������ź�ɫ��̺��ǽ���Ϲ���һ�����ң�����д��������ɫ�Ĵ�
�֡�������̡�����ǰ������һ�����磬�ϻ�һ��������ͨ���ɫ��
������צ�����˳���
LONG
        );
        set("exits", ([
                "south" : __DIR__"neiyuan",
                "north" : __DIR__"houtin",
        ]));

	set("objects", ([
            __DIR__"npc/rysj_guard" : 2,
        ]));

	set("cost", 1);
	setup();
}

void init()
{
	object *guard, me = this_player();
	int i, j;

	if ( interactive(me) ) {
		guard = all_inventory(environment(me));

                for ( i=0; i<sizeof(guard); i++ ) {
                        if ( guard[i]->query("id") == "rysj weishi" ) {
                                guard[i]->kill_ob(me);
				j++;
			}
                }

		if ( j ) message_vision("��ʿ������$N�ȵ������ߺ��ˣ�����˽����̷ֶ棡��������\n", me);
	}
}
	

int valid_leave(object me, string dir)
{
        object room, *guard;
	int i, j;

        if( dir == "north"  ) {
		guard = all_inventory(environment(me));

		for ( i=0; i<sizeof(guard); i++ ) {
			if ( guard[i]->query("id") == "rysj weishi" ) {
				guard[i]->kill_ob(me);
				j++;
			}
		}

		if ( j ) return notify_fail("��ʿ����ȵ������У������봳�뱾���صأ�\n");
        }

        return ::valid_leave(me, dir);
} 
