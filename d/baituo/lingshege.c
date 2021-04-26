// Code of ShenZhou
// ���ոİ�
// maco 2/17/2000
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "���߸�");
        set("long", @LONG
���ǡ�������ŷ���������ң�Ҳ������֮�أ��յ����ķ�������
��һ����ɱ֮������ͷľ���ϰ���һ�����ݣ����Է��ŵ�ʯǽ�ϻ���һ
���ſ������˫ͷ���ߣ�����ʮ�ֹ��졣�̵�ʯ��ķ�϶�в���������
��֮�������д�Ⱥ�����ڵذ������������
LONG
        );
        set("exits", ([ 
	    "east" : __DIR__"changlang2",
	    "down" : __DIR__"base1",
           "west" : __DIR__"houyuan",
        ]));

        set("objects", ([ 
            CLASS_D("baituo")+"/feng" : 1,
         "/d/baituo/npc/snake" : 2,
         ]) );
	set("cost", 1);
	create_door("down", "�ܽ�ʯ��", "up", DOOR_CLOSED);
        
        setup();
}

int valid_leave(object me, string dir)
{
	object feng;

    if (dir == "down") {
	if (feng = present("ouyang feng", environment(me)) ) {
	if (me->query("family/family_name")!="����ɽ"){ 
		feng->kill_ob(me);
		return notify_fail("ŷ����ŭ�ȵ�����������Ұ�֣�����˽���Ϸ�����ң���\n");
	}
	if (me->query("family/generation")>3) {
		command("pat "+me->query("id"));
		return notify_fail("ŷ����˵������������ׯ����ó�Щ����������ȥ�����ɡ�\n");
	}
	}
    }
    return ::valid_leave(me,dir);
}
 
	

