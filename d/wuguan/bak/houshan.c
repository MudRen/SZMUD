//Cracked by snso k1-7-6
// Room: houshan1.c ��ɽ

inherit ROOM;
#include <ansi.h>

void reset();
int valid_leave();

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
���������ݵĺ�ɽ�ˣ�ɽ��������ľïʢ���峺��Ϫ����������һ
��Сͤ�ӣ�����Ϫˮ��������ȥ������ɽ�����������ԣ����ϴӶ��ߺ�Х
�������Ӹ����£���Ŀ����������Զ������˷�������ɽ�����ơ�������
һƬ���֣���ľʮ��ï�ܡ����������������һ��������Ȼ�ľ�������
����һȺС��ɹ����ͷ��������ͯ�Ĵ��������Ǹ�����da���ĺû�
������
LONG
    );

	set("exits", ([
	    "southwest" : __DIR__"xiaojing1",
	    "west" : __DIR__"shulin9",
	    "east" : __DIR__"shulin6",
	    "north" : __DIR__"shulin1",
	    "northwest" : __DIR__"shulin"+(4+random(5)),
	    "northeast" : __DIR__"shulin"+(6+random(3)), 
	    ]));

/*	set("objects", ([
            __DIR__"npc/dizi2" : 1,
	    ]));*/

        set("no_clean_up", 0);
        set("outdoors", "wuguan" );
        set("cost", 0);
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_hit", 1);
    setup();
    //replace_program(ROOM);
}
void init()
{
   object me = this_player();

   if ( interactive(me) && me->query("wuguan/job_pending") ) {
	me->set_temp("wuguan_job/hs", 1);
   }
   
        add_action("do_da", "da");
}

int do_da()
{
        object me;
        int i, kar, cps, bb, mm;
        me = this_player();
        
        if (me->query("combat_exp")>=1000)
             	return notify_fail("���Ѿ������ô����������ˡ�\n");
    	
        if(me->is_busy())
             	return notify_fail("������������ˣ��㻹��һ���������ɣ�\n");
             	
        if(me->query("jingli")<30)
             	return notify_fail(HIR"�㻹������Ϣһ�°ɣ����ҲҪ������Ӵ����\n"NOR);

        message_vision("$N�����ʱ��ˣ�õ�С��С������׼���ϵ�Сȸ��ȥ......\n", me);
        message_vision("$Nֻ������һ�����������\n",me);
        me->start_busy(random(3) + 2);        
        kar = me->query("kar");
        
        if (random(kar)== 25) {
                message_vision("$N��һֻ"HIW"������\n"NOR, me);
                bb= 20 + random(kar);
        	mm= 20 + random(kar / 2);
                me->add("combat_exp",bb);
                me->add("potential",mm);
                tell_object(me,HIC"��õ���"+HIG+chinese_number(bb)+NOR+HIC+"��"+HIR+"����\n"NOR);
                tell_object(me,HIC"��õ���"+HIG+chinese_number(mm)+NOR+HIC+"��"+HIW+"Ǳ��\n"NOR);
		me->receive_damage("jingli", 15, "����͸֧��������");
        	return 1;
                }
       
        if (random(kar)>20) {
	        message_vision("$N��һֻ"HIY"��˿ȸ��\n"NOR, me);
                bb= 10 + random(kar);
        	mm= 10 + random(kar / 2);
                me->add("combat_exp",bb);
                me->add("potential",mm);
                tell_object(me,HIC"��õ���"+HIG+chinese_number(bb)+NOR+HIC+"��"+HIR+"����\n"NOR);
                tell_object(me,HIC"��õ���"+HIG+chinese_number(mm)+NOR+HIC+"��"+HIW+"Ǳ��\n"NOR);
		me->receive_damage("jingli", 15, "����͸֧��������");
        	return 1;	
        }
        
        if (random(kar)>10) 
            {
                message_vision("$N��һֻ"HIG"���ġ�\n"NOR, me);
         	bb = 5 + random(kar);
        	mm= 5 + random(kar / 2);
                me->add("combat_exp",bb);
                me->add("potential",mm);
                tell_object(me,HIC"��õ���"+HIG+chinese_number(bb)+NOR+HIC+"��"+HIR+"����\n"NOR);
                tell_object(me,HIC"��õ���"+HIG+chinese_number(mm)+NOR+HIC+"��"+HIW+"Ǳ��\n"NOR);
		me->receive_damage("jingli", 15, "����͸֧��������");
        	return 1;
       }

        if (random(kar)>5) 
            {
                message_vision("$N��һֻ"YEL"��ȸ��\n"NOR, me);
        	bb= 1 + random(kar) / 2;
        	mm= 1 + random(kar / 2);
                me->add("combat_exp",bb);
                me->add("potential",mm);
                tell_object(me,HIC"��õ���"+HIG+chinese_number(bb)+NOR+HIC+"��"+HIR+"����\n"NOR);
                tell_object(me,HIC"��õ���"+HIG+chinese_number(mm)+NOR+HIC+"��"+HIW+"Ǳ��\n"NOR);
		me->receive_damage("jingli", 15, "����͸֧��������");
        	return 1;
       }
        else 
           {
                me->receive_damage("jingli", 10, "����͸֧��������");  
                message_vision("$NʲôҲû�򵽡�\n",me );
	     }
       	return 1;
}