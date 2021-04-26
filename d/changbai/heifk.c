// Code of ShenZhou
// Room: heifk.c
//change bu Wzfeng 99 12

inherit ROOM;
#include <ansi.h>
int do_search(string arg);
void create()
{
        set("short", "�ڷ��");
        set("long", @LONG
�����ǳ���ɽ��һ���գ�����ɽ�±������м���༸�׵Ŀ�ȡ�����ǰ
��û���ڵ������ܸ�������Ӱ�죬ǿ����������Ӵ˴���Х����������֮ǿ
��������ţ��������ᱻ�����ߡ������е��˴�������С�������ʽ�
ɽ���ϵ��Ӳ�����������
LONG    );
        set("exits", ([ 
              "westdown" : __DIR__"milin4",
              "eastdown" : __DIR__"jiaxz",
        ]));
        
        set("outdoors", "changbai");
		set("cao_time",9);
  


      set("cost", 8);

        setup();
}

void init()
{       
        object me = this_player();
        int power;

        power = (int)me->query("neili") * (int)me->query("dex");

        if( random(power) < 3000 && interactive(me) ) {
                message_vision(HIR"һ�ɿ���Х������$Nֻ��������һ�ᣬ�ѱ������������ɽ�£�\n"NOR,me);
                me->move(__DIR__"baihe");
                me->unconcious(); 
        } else {
                me->add("neili", -10);
                message_vision(HIB"һ�ɿ���Х������$N������ҡҡ�λΣ����ˤ��ɽȥ��\n"NOR, me);
        } 
		add_action("do_search",  "search");

}

int do_search(string arg)
{
        
		object cao,me;
		int i;
		me = this_player();
		
        if(me->query_skill("pixie-jian",1)<200)
		{
		tell_object(me, "ʲô��\n");
        return 1;
		}
		if(me->query("neili")>2000)
		{
			if(query("cao_time")>3)
				{
				tell_object(me, "����ϸѰ�ң�����ɽ�����м�������ɫ��С�ݡ�\n"
				"������������ȥ��С�������ժ�¼���С�ݷ������ϡ�\n");
				me->add("neili",-1000);
				for(i=1;i<4;i++)
				{
					cao = new("/d/changbai/obj/yinyang-cao");
					cao->move(me);
					add("cao_time",-1);
				}
			}
			else
			{
				tell_object(me, "����ϸѰ���˰��죬ȴʲô��û�ҵ���\n");
			}

		}
		else
		{
			tell_object(me, "����ϸѰ�ң�����ɽ�����м�������ɫ��С�ݡ�\n"
			"������������ɽ�¡���Ȼһ�����紵������һ���������㣬���ص�ˤ��������\n");

		}
		return 1;
}

