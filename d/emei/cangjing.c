// Code of ShenZhou
// /d/emei/cangjing.c �ؾ���
// Shan: 96/09/23

#include <room.h>
inherit ROOM;

void create()
{
        set("short", "�ؾ���");
	set("long", @LONG
С��¥�ϱ��Ƕ����ɵĲؾ����ˡ����ﶼ���������飬�߼��������ܡ�
��������һ�Ŵ����ӣ����Ϸ��˼����𾭡��и�Сʦ̫�����򾲵�ʦ̫���顣
LONG
	);
	set("exits", ([
		"down" : __DIR__"chuwu",
	]));

        set("objects",([
                "d/emei/obj/yugajing0" : 1,
                "d/emei/obj/yugajing2" : 1,
                CLASS_D("emei") + "/jingdao" : 1,
        ]));

	set("cost", 0);
	setup();

}

int valid_leave(object me, string dir)
{
        if (  (dir == "down") && ( present("shu", this_player()) ) 
           && objectp(present("jingdao shitai", environment(me))) ) {
        message_vision("����ʦ̫��$N��Ѿ������ߣ���ǰ˵���������鲻��衣\n", me);
        return notify_fail("\n");
        }

        return ::valid_leave(me, dir);
}


