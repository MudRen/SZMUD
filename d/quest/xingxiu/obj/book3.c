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
              set("no_drop",1);
              set("no_get",1);
              set("no_steal",1);
        if( clonep() )
        set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("long", "����һ�����ľ��飬ÿһҳ�϶�д�������������֣�ûһ��ʶ�á�\n");
                set("value", 5000);
                set("material", "paper");
                
        }
}

int do_xiulian()
{
        object me;
        object where_1;
        int poison_lvl;
        me=this_player();
        if(!me->query_skill("poison",1))
        return notify_fail("���������Ķ��������ᣬ����������ô����ļ��ɣ�\n");
         
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
        if( me->is_fighting() )
                return notify_fail("ս���в������������߻���ħ��\n");

        if( me->query("rided"))
                return notify_fail("�����������������߻���ħ��\n");
        if(me->query("canewhua")==1)
                return notify_fail("���޷��ٴ��Ȿ����ѧ���κ��¶����ˡ�\n");
        if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("��������� enable �����󷨡�\n");
        if (poison_lvl < 250) 
                return notify_fail("��һҳ�����һЩ�ö����ɣ�����ôҲ���Բ��ˣ�������Ķ������д���ǿ��");
        

        if(present("yijinjing",me) && present("shenmu wangding",me) && present("shemu wangding",me)->query("fake")==1)
                return notify_fail("�����˰��죬��ľ����û�а�㶯���������Ǹ��ٻ���\n");
                
        if(present("yijinjing",me) && !present("shenmu wangding",me))
        {
                write("�㿪ʼ���ն��������Ķ�������������Ϣ������\n");
                if(random(4)==1){
                        write("û����ľ�����İ�����������޷�����ס�Լ���������ֻ�������ں��ֱײ������Щ���ǲ����ˣ�\n");
                        write("���۵��³�һ����Ѫ����ֻ������ʶ����������ʧ��\n");
             me->receive_damage("qi",me->query("eff_qi")+200,"�����߻���ħ����");
                        return 1;
                }
                else
                me->start_busy(30);
                call_out("finish",60);
                return 1;
        }
        write("�㿪ʼ�����׽������ص�����������ʼ��Ϣ������\n");
        write("��ľ����Ҳð�������������̣�һ�ж���������ú�г���ˣ��������������������ҵĴ��ڡ�\n");
          if (random((int)(200/me->query("int")))>3)
          {
                write("��Ȼ���������������Щ���ң������ĸ��ط������ˣ�\n");
                write("���۵��³�һ����Ѫ����ֻ������ʶ����������ʧ��\n");
                me->unconcious(); 
                             return 1;
                }
         else
         {
        me->start_busy(30);
        call_out("finish",60);
          }
        return 1;
}

int finish(object me)
{
        me=this_player();
          write("��ֻ���û��������泩�ޱȣ����ɰ���̾�������治�����׽����\n");
          me->clear_condition("bingcan_poison",5);
        if((int)me->query("yijinjing")<1)
        {
                me->set("yijinjing",1);
        }
        me->add("yijinjing",1);
        if((int)me->query("yijinjing")>=10)
        {
                write("����̨��ȻһƬ���ʣ�������������һɨ���գ���������˻�����������������ڣ�\n");
                me->delete("yijinjing");
                me->set("canewhua",1);
                me->clear_condition("bingcan_poison");
                    return 1;
                //ѧ��yun hua
         }
            return 1;
}


