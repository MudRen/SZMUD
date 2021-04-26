//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "��Ȫ��");
        set("long", 
"��Ȫ��Ϊ��ɽʮ�˾�֮һ������������Ȫˮ�����������
�ɣ�Ȫˮһ��һ�𣬱�����ν�ġ���Ȫ�ʿࡱ����������¡��
�����ε��ˣ��������顰��Ȫ�ۡ����Ҷ\n"
        );
        set("exits", ([
                "westdown"  : __DIR__"zizhiyu",
                "eastup"  : __DIR__"chuyundong",
]));
        set("no_clean_up", 0);
        set("resource/water", 1);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        //replace_program(ROOM);
}
void init()
{
        add_action("do_drink", "drink");
}
int do_drink(string arg)
{	
        if(arg !="ganquan") 
	        return notify_fail("��Ҫ��ʲô? \n");
        else{

        int current_water,current_food;
        int max_water;
        object me;

        me = this_player();
        current_water = me->query("water");
	current_food = me->query("food");
        max_water = me->query("str")*10 + 100;
        if (current_water<me->max_water_capacity()) {
            me->set("water", current_water+30+random(20));
	    me->set("food", current_food+20+ random(10));
            message("vision", me->name()+"������������һ�Ѹ�Ȫˮ������ȥ��\n"
            , environment(me), ({me}) );
            write("������һ�Ѹ�Ȫ������ȥ��Ȫˮһ���ظ����������¶���ģ�ˬ͸������\n");
	 if ((int)me->query("eff_qi") != 
            (int)me->query("max_qi"))
            me->receive_curing("qi", 10+random(10));

        }
        else write("���Ѿ����˺ö�Ȫˮ���Ѿ���Ҳ�Ȳ����ˡ�\n");

        return 1;
	}
}
