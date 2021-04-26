 // Code of ShenZhou
// jindian.c ��� 
// by Fang 8/20/96
// Update By Scatter
// V 1.0

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY"���"NOR);
        set("long", @LONG
����м乩��������ͭ���������㣬��̬�����������н�ͯ��Ů������
�Ϲ�����ˮ�������������ׯ�ϡ���ǰ������Ϊͭ��������͵���ͭ�񡢹�
��í��һ�壬������ȷ�����ɸ߳���
LONG
        );
//        set("outdoors", "wudang");

        set("exits", ([
                "north" : __DIR__"zijin",
        ]));
        set("cost", 1);
        setup();
}

  void init()
{
    add_action("lingwu","lingwu");
}

int lingwu()
{
    object me = this_player();
    int rndnmb=random(500);

    if(me->is_busy())
        return notify_fail("������æ�أ�\n");
    if(me->query("zhenwu/5x"))
        return notify_fail("���Ѿ�������\n");
    if(!me->query("zhenwu/6x"))
        return notify_fail("�����ұ���ѧ��ɣ������Ϳ�������\n");
        if(!me->query("family")||me->query("family/family_name")!="�䵱��")
        return 0;
    if(me->query("combat_exp")<100000)
        return notify_fail("���ʵս���鲻�㣬����û��ѧ�������߽��󡹣�\n");
      if(me->query_skill("taiji-shengong",1)<100)
        return notify_fail("����ڹ��ķ�������ѧ�������߽��󡹶����к����棡\n");
    if(me->query_skill("taoism", 1)<100)
        return notify_fail("��Ե�ѧ�ķ��������˽⣬������ᡸ�����߽��󡹵����⣡\n");
    if(me->query("max_neili")<1000)
        return notify_fail("��������������ã���ȥ��û�����������ɣ�\n");
      if(me->query_skill("parry",1)<100)
        return notify_fail("�䵱��ѧ������˸գ�����һ����ʽ���мܲ�ס����ôѧ�������߽��󡹣�\n");
    if(me->query("max_jingli")<1000)
        return notify_fail("���������߽��󡹲���һ��һϦ���£��Ѿ�������һ����������ɣ�\n");
        if ( me->query("jingli") < 2000 )
                {
                                command("say ��ϰ�������߽��󡹲���һ��������£��ҿ��������ڵ����������ʺ�����");
                                return 1;
                }
                if ( me->query("neili") < 2000)
                {
                        command("say ��ϰ�������߽��󡹲���һ��������£������ڵ����������ʺ�����");
                        return 1;
                }


    
                message_vision(NOR"$N������ĥ����Ҫ����\n"NOR, me);

        if(rndnmb<460)
        {
                me->add("jing",-10);
                me->start_busy(10);
                                me->unconcious();
                                message_vision(HIR"$NͻȻһ����ѣ����ǰ��һ���ƺ����ڴ�ת����\n"NOR, me);
        return 1;
        }

    me->set("zhenwu/5x",1);
    message_vision(HIC"$N�����󷨣��鶯�糤�ߣ��������ڹ꣬���󷨴�������\n"NOR, me);
    return 1;
}

