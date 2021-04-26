// Code of ShenZhou
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
����������ɮ����Ϊ����ˮר�ſ������һ��С·������ɽ
·ֻ����һ�������ߡ�����Ϊ������Щ��ɮ�ܹ����õ������͹�
����ˮ���˱���ƽ��˫����Ͱ���С�ɽ·������������ʪ�ֻ���
һ��С�ľͻ�ˤ����ͷ��

LONG
        );

        set("exits", ([
                //"eastup" : __DIR__"pinglu",
                "southdown" : __DIR__"riverbank",
        ]));
	switch( random(3) ){
	case 0 : 
		set("exits/up", __DIR__"shanlu1");
		break;
	case 1 :
		set("exits/westup", __DIR__"shanlu1");
		break;
	case 2 :
		set("exits/northwest", __DIR__"shanlu1");
		break;
	default :
		set("exits/northup", __DIR__"shanlu1");
		break;
	}

        set("outdoors", "shaolin");
        set("cost", 5);
        setup();
}

int valid_leave(object me, string dir)
{
        object ob;
	ob = present("shui tong", me);
	if( random((int)me->query("kar")) <= 3){
		me->receive_damage("qi", 30, "��ɽ��ˤ����");
                me->receive_wound("qi",  20, "��ɽ��ˤ����"); 
		if (ob){
			if (random(30) == 1) {
			message_vision(HIB"$NͻȻ����һ�������˸����򣬻���ûˤ����\n"NOR, me);
			message_vision(HIR"$Nȴ����ˮͰ��С��ײ����·�ߵ�ʯͷ�ϣ�ײ�˸����飡\n"NOR, me);
			destruct(ob);
			}
		else{	     
            message_vision(HIG"$N����һ������С��ˤ�˸���ͷ��\n"NOR, me);
			message_vision(HIG"���Ͱ���ˮȫ������ȥ�ˣ�\n"NOR, me);
			ob->delete("full");
			ob->set("water_level",0);
			
		}
		}
		else			
				{
                message_vision(HIR"$N����һ�������˸��գ�\n"NOR, me);
				me->move("/d/shaolin/riverbank");
                return notify_fail(HIR"���ɽ�Ϲ���������ֻ���û����޴����ۣ������˼����ˡ�\n"NOR);
        }
	}
        return ::valid_leave(me, dir);
}
                
