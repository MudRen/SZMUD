// Code of ShenZhou
// ling.c
inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(YEL"������"NOR, ({ "tieyan ling","ling"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "������������<������>�����̵��ӱ�������Я�������򲻿ɶ�ʧ���������������롣\n"
						"ƾ����������ܣ�\n"
						"�����������������ֵ�����书(qingjiao <ĳ��> <����>)��\n");
                set("value", 0);
                set("material", "iron");
				set("no_get",1);
				set("no_drop","��������������ܶ�����\n");
				
				set("no_give","��������������ܸ��ˡ�");
				set("no_insert", 1);
         }
	setup();
}
int query_autoload()
{
	return 1;
}
int init()
{
	add_action ("do_qingjiao", "qingjiao");
}

int do_qingjiao(string arg)
{
	
	string skill, teacher, master, skill_name, slow_msg;
	object ob;
	int master_skill, my_skill, gin_cost,i,teach_falg,slow_factor;
	int tmp, learn_times;

	mixed master_allskill;
	
	
	object me=this_player();
	mapping fam = me->query("family");
	mapping fam_ob;
    if (me->is_busy())
		return notify_fail("��������æ���ء�\n");

    if(!arg)
		return notify_fail("ָ���ʽ��qingjiao <ĳ��> <����> [����]\n");

    if (sscanf(arg, "%s %s %d", teacher, skill, learn_times)!=3 ) {
		learn_times = 1;
        if (sscanf(arg, "%s %s", teacher, skill)!=2 )
			return notify_fail("ָ���ʽ��qingjiao <ĳ��> <����> [����]\n");
        }
	if (learn_times < 1) 
		return notify_fail("ָ���ʽ��qingjiao <ĳ��> <����> [����]\n");
    if( me->is_fighting() )
		return notify_fail("����ĥǹ������������\n");

    if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("��Ҫ��˭��̣�\n");

   if( !living(ob) )
	   return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");
   fam_ob = ob->query("family");	
   if (fam_ob["family_name"] != "����")
	   return notify_fail("��ֻ���������е��ֵ�����书��\n");


   if( (int)me->query("potential") < learn_times )
       return notify_fail("���Ǳ�ܲ�����û�а취�ٳɳ��ˡ�\n");

	if(ob==me)
		return notify_fail("�Լ����Լ���̣�\n");
	if (fam["family_name"] != "����")
		return notify_fail("����������ֵܣ���θ����������,��Ȼ���������ֽ̹��򣿿���wzfeng�㱨��õ�������ķ�����\n");

	if(!master_allskill=ob->query("teach_skillsname"))
		return notify_fail(ob->name()+"ûʲô������̵��书��\n");
		if(skill=="literate")
	{
		return notify_fail(ob->name()+"˵��������д��ֻ�ܿ���ƽʱ�Լ�����Ժѧϰ���Ҳ��ܴ����㡣\n");

	}

	i=sizeof(master_allskill);
	if(i=sizeof(master_allskill))
		for(i=0;i<sizeof(master_allskill);i++)
			if(master_allskill[i]==skill)
				teach_falg=1;
	if(!teach_falg)
		return notify_fail(ob->name()+"���ܴ����������书��\n");
		
	if( ob->prevent_learn(me, skill) )
		return 1;

	my_skill = me->query_skill(skill, 1);
	master_skill = ob->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail(ob->name()+"�Ǻ�һЦ����������Ѿ��������ң������ﻹ�ҽ̸���ʲô��\n");

	
	if( !SKILL_D(skill)->valid_learn(me) ) return 0;
	 
	slow_factor = 1;
    slow_msg = "";

        
	gin_cost = 150 / (int)me->query("int");
    if( !my_skill ) 
	{
		gin_cost *= 2;
        me->set_skill(skill,0);
    }
     printf("����%s����йء�%s�������ʡ�\n", ob->name(), to_chinese(skill));

     if( ob->query("env/no_teach") )
		 return notify_fail("����" + ob->name() + "���ڲ���׼���ش���ʲô��\n");

	 tell_object(ob, sprintf("%s��������йء�%s�������⡣\n", me->name(), to_chinese(skill)));

    if( (int)ob->query("jing") > learn_times*gin_cost/5 + 1 ) {
            if( userp(ob) ) ob->receive_damage("jing", learn_times*gin_cost/5 + 1);
    } else {
            write("����" + ob->name() + "��Ȼ̫���ˣ�û�а취����ʲô��\n");
            tell_object(ob, "������̫���ˣ�û�а취��" + me->name() + "��\n");
            return 1;
    }

	gin_cost = learn_times * gin_cost*3/2;
        
        if( (int)me->query("jing") > gin_cost ) {
                if( (string)SKILL_D(skill)->type()=="martial"
                &&      my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) {
                        printf("Ҳ����ȱ��ʵս���飬���%s�Ļش������޷���ᡣ\n", ob->name() );
                } else {
                    if(skill_name = SKILL_D(skill)->query_skill_name(my_skill)) {
                            printf("������%s��ָ����%s�ԡ�%s����һ���ƺ���Щ�ĵá�\n", 
                                    ob->name(), slow_msg, skill_name);
                    }
                    else
                        printf("������%s��ָ����%s�ƺ���Щ�ĵá�\n", ob->name(), slow_msg);

                    me->add("potential", -learn_times);

                    tmp = 0;
                    for (i=0; i<learn_times; i++)  tmp += random(me->query_int());
        
	     me->improve_skill(skill, tmp/slow_factor);

                }
        } else {
                gin_cost = me->query("jing") > 0 ? (int)me->query("jing") : 0;
                write("�����ھ��񲻹����޷���"+ob->name()+"���"+to_chinese(skill)+"��\n");
				return 1;
        }

        me->receive_damage("jing", gin_cost);

        return 1;
}





