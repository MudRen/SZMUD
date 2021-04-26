//bingying for scheme do job
#include <ansi.h>;
#define BUSY_TIME 180

inherit ROOM;

void create()
{
        set("short", "СУ��");
        set("long", @LONG
����������Ӫ��СУ����ƽʱ��ʿ�Ǿ���������������Ϻ�ƽ����
������ָ��̨���и��������ɵ���ˣ��˶�һ������һ������������
Ӫ��ɫ����ӭ���������졣ƽʱ��ʿ��һ�����������ϳ��٣������
����������Ұս����������ʳ����Ѳ�ߡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	"north" : __DIR__"biaoqiyin",
		]));
        set("objects", ([
                __DIR__"npc/xxbing2" : 3,
                __DIR__"npc/wujiang" : 1,
        ]));
        set("cost", 1);
        set("outdoors", "xixia");
        set("no_fight",1);
        setup();
}

void init()
{
        add_action("do_fengyao","caolian");
}

int do_fengyao()
{
        object me = this_player();
        int bonus,exp,pot;
        object mon;
        if( time() < me->query("mp_job_time") + BUSY_TIME ) 
              return notify_fail("�ող����꣬��Ϣһ�°ɡ�\n");
        if( (int)me->query_temp("fengyao") ) 
              return notify_fail("���Ѿ��ڹ����ˡ�\n");
        if( (int)me->query("balance") < 5 ) 
        {
              tell_object(me,HIR"\nÿ�β������Ǯׯ���ٱ��������ͭǮ��\n\n\n"NOR);
              return 1;
        }
        if( (int)me->query("combat_exp") < 100000 ) 
              return notify_fail("����书̫�������ȥ��Щ��������(100k ����)��\n");
        if( (int)me->query("shen") > 100 ) 
              return notify_fail("��ͷ�������ϸ����Ը����㡣\n");
        tell_object(me, CYN "\n�㶨�˶��񣬿�ʼ����У���ϵĽ�ͷ��һ��һʽ�ز����ˡ�\n" NOR);
        me->set_temp("fengyao",1);
        me->add("balance",-5 );
        me->set("mp_job_time",time() );
        me->start_busy(60);
        me->set_temp("apply/short", 
                ({ HIW"���ı�Ӫ "NOR+me->query("name")+"("+capitalize(me->query("id"))+")"HIG" < ѵ �� �� >"NOR""})); 
        call_out("del_fengyao", 120, me, mon, bonus, exp, pot);
        return 1;
}

void del_fengyao(object me, object mon, int bonus, int exp, int pot)
{
        me->delete_temp("fengyao");
        tell_object(me,HIB"\n����һ����в�������о�����ٱ�����־���\n\n\n"NOR);
        tell_object(me,HIY"��Ȼ�۵����ᱳʹ�����������㳤��һЩ�򶷾��顣\n\n\n"NOR);
        me->add("combat_exp",50 + random (40));
        me->delete_temp("apply/short"); 
        me->add("caolian/ca",1);
        return ;
}

int valid_leave(object me, string dir)
{
        if (dir =="north" && this_player()->query("scheming") )
        return notify_fail("����ľͷľ�Եģ����Ǵ�������ɣ�Ҫ�뿪���� scheme stop��\n");
        return ::valid_leave(me, dir);
}
