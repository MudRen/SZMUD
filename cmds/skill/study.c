// Code of ShenZhou
// study.c
// Modified by Rama 05/04/02
// �����˿���ָ��Study ����

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object where = environment(me);
        object ob;
        string zhao_name, book_name;
        mapping skill;
        int my_skill, cost, times;

       
        if (! arg) 
                return notify_fail("��Ҫ��ʲô��\n");
 
        if (where->query("pigging"))
                return notify_fail("�㻹��ר�Ĺ���ɣ�\n");

        if (where->query("sleep_room"))
                return notify_fail("��˯���ﲻ�ܶ��飬���Ӱ�����ˡ�\n");

        if (where->query("no_fight"))
                return notify_fail("���ﲻ�Ƕ���ĵط���\n");

        if (me->query_temp("cursed", 1))
                return notify_fail("ʲô��\n");

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if( me->is_fighting() )
                return notify_fail("���޷���ս����ר�������ж���֪��\n");
               
        if ( sscanf(arg, "%s for %d" , book_name, times ) != 2 ) 
        {
                times=1;
                if( sscanf(arg, "%s", book_name) != 1)
                        return notify_fail("ָ���ʽ��study|du <�鼮> for <����>\n"); 
        }


                if (times > 300)
                        return notify_fail("���а취һ�ο���ô����\n");

        if (! objectp(ob = present(book_name, me))) 
                      return notify_fail("�ף����Ȿ��ô��\n"); 

        if( !mapp(skill = ob->query("skill")) )
                return notify_fail("���޷�����������ѧ���κζ�����\n");

        if( !me->query_skill("literate", 1) )
                return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");


        if( ob->query("id") == "jiuying zhenjing" && !stringp(me->query("9yin")) ){
                message_vision("$N������֭Ҳ���������Ȿ$n��\n",me,ob);
                return 1;
        }

        message("vision", me->name() + "��ר�ĵ��ж�" + ob->name()
                + "��\n", environment(me), me);


 if ( times < 1 )  
 return notify_fail("�㲻��ָ������Ϊ�������㡣\n"); 
        if( (int)me->query("combat_exp") < skill["exp_required"] ) {
                write("���ʵս���鲻�㣬����ô��Ҳû�á�\n");
                return 1;
        }

        notify_fail("����Ŀǰ����������û�а취ѧ������ܡ�\n");
        if( !SKILL_D(skill["name"])->valid_learn(me) ) return 0;

        cost = (skill["jing_cost"] + skill["jing_cost"] 
                * (skill["difficulty"] - (int)me->query("int"))/20) * times;
        if (cost < 10) cost = 10; // minimum cost

        if( me->query_skill(skill["name"], 1) > skill["max_skill"] ) {
                write("���ж���һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
                return 1;
        }

        if( !me->query_skill(skill["name"], 1) ) me->set_skill(skill["name"], 0);

        my_skill = me->query_skill(skill["name"], 1);

        if( (int)me->query("jing") > cost ) {
                if( (string)SKILL_D(skill["name"])->type()=="martial"
                && my_skill > me->max_skill((int)me->query("combat_exp")) ) {
                        printf("Ҳ����ȱ��ʵս���飬���%s������˵�Ķ��������޷���ᡣ\n", ob->name());
                } else {
                        if(zhao_name = SKILL_D(skill["name"])->query_skill_name(my_skill))
                                printf("���ж��й�%s�ļ��ɣ��ԡ�%s����һ���ƺ���Щ�ĵá�\n", 
                                        to_chinese(skill["name"]), zhao_name);
                        else
                                printf("���ж��й�%s�ļ��ɣ��ƺ��е��ĵá�\n", to_chinese(skill["name"]));
                        me->improve_skill(skill["name"], ((int)me->query_skill("literate", 1)/5+1) * times);
                }
        } else {
                cost = me->query("jing");
                if (cost < 0) cost = 0;
                write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
        }

        me->receive_damage("jing", cost, "�����ʴ�����");

        return 1;
}

int help(object me)
{
   write( @HELP
ָ���ʽ: study|du <�鼮> for <����>

���ָ��ʹ�����ͨ���Ķ����Ż�������Ʒ��ѧĳЩ����,
��ǰ����: �㲻���Ǹ�����ä����

see also : learn
HELP
   );
   return 1;
}

