//rama@sz
//�׽��ƪ

inherit ITEM;
inherit SKILL;

int do_xiulian();
int finish(object me);

void setup()
{}
void init()
{
        add_action("do_xiulian", "xiulian");
}

void create()
{
        set_name("�׽��ƪ", ({ "yijinjing" }));
        set_weight(600);
        if( clonep() )
        set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ�����ľ��飬ÿһҳ�϶�д�������������֣�ûһ��ʶ�á�\n");
                set("value", 5000);
                set("material", "paper");
                set("skill", ([
                        "name":                 "force",        // name of the skill
                        "exp_required": 2000000,                // minimum combat experience required
                        "jing_cost":    50,                     // jing cost every time study this
                        "difficulty":   20,                     // the base int to learn this skill
                        "max_skill":    300                     // the maximum level you can learn
                        ]) );
        }
}

int do_xiulian()
{
        object me;
        object where_1;
        int poison_lvl;
        me=this_player();
        if(!me->query_skill("poison",1))
        return notify_fail("���������Ķ��������ᣬ����������ô����ļ��ɣ�\n");;
        
        poison_lvl = me->query_skill("poison",1);
               
        where_1 = environment(me);

        if (!present("yijinjing", me))
                return 0;
                
        if (where_1->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

        if (where_1->query("sleep_room"))
                return notify_fail("������˯�������������Ӱ�����ˡ�\n");

        if (where_1->query("no_fight"))
                return notify_fail("����������ã������ұ𴦰ɣ�\n");

        if (where_1->query("name") == "����")
                return notify_fail("����̫����, �������߻���ħ. \n");

        if (me->is_busy() || me->query_temp("pending/exercising"))
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("ս���в������������߻���ħ��\n");

        if( me->query("rided"))
                return notify_fail("�����������������߻���ħ��\n");
        if(me->query("hua/done"))
                return notify_fail("���޷��ٴ��Ȿ����ѧ���κ��¶����ˡ�\n");
        if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("��������� enable �����󷨡�\n");
        if (poison_lvl < 250) 
                return notify_fail("��һҳ�����һЩ�ö����ɣ�����ôҲ���Բ��ˣ�������Ķ������д���ǿ��");
        

       if(present("yijinjing",me) && !present("shenmu wangding",me))
        {
                write("�㿪ʼ���ն��������Ķ�������������Ϣ������\n");
                me->start_busy(30);
                if(random(2)==1){
                        write("û����ľ�����İ�����������޷�����ס�Լ���������ֻ�������ں��ֱײ������Щ���ǲ����ˣ�\n");
                        write("���۵��³�һ����Ѫ����ֻ������ʶ����������ʧ��\n");
             me->receive_damage("qi",me->query("eff_qi"));
                        return 0;
                }
                else
                call_out("finish",51);
                return 1;
        }
        write("�㿪ʼ���ն��������Ķ�������������Ϣ������\n");
        write("��ľ����Ҳð�������������̣�һ�ж���������ú�г���ˣ��������������������ҵĴ��ڡ�\n");
        me->start_busy(30);
        call_out("finish",51);
        return 1;
}

int finish(object me)
{
        write("��ֻ���û��������泩�ޱȣ����ɰ���̾�������治�����׽����\n");
        if((int)me->query("yijinjing")<1)
        {
                me->set("yijinjing",1);
        }
        me->add("yijinjing",1);
        if((int)me->query("yijinjing")>=3)
        {
                write("Congratulations!!You got it!!");
                me->delete("yijinjing");
                me->set("hua/done");
                //ѧ��yun hua + improve 1 level huagong-dafa
        }
}



