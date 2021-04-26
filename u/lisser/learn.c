// Code of ShenZhou
// learn.c

#include <skill.h>

inherit F_CLEAN_UP;

string *reject_msg = ({
	"˵������̫�����ˣ�����ô�ҵ���\n",
	"�����ܳ�����һ����˵������̣�����ô�ҵ���\n",
	"Ц��˵��������Ц�ˣ��������С�������ʸ�ָ�㡹��ʲô��\n",
});

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	string skill, teacher, master, skill_name, slow_msg;
	object ob;
	int master_skill, my_skill, gin_cost, slow_factor;
  	int i, tmp, learn_times;


        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

	if(!arg)
	    return notify_fail("ָ���ʽ��learn|xue <ĳ��> <����> [����]\n");

  	if (sscanf(arg, "%s %s %d", teacher, skill, learn_times)!=3 ) {
	    learn_times = 1;
	    if (sscanf(arg, "%s %s", teacher, skill)!=2 )
		return notify_fail("ָ���ʽ��learn|xue <ĳ��> <����> [����]\n");
	}
	if (learn_times < 1) 
		return notify_fail("ָ���ʽ��learn|xue <ĳ��> <����> [����]\n");

	if( me->is_fighting() )
		return notify_fail("����ĥǹ������������\n");

	if( !(ob = present(teacher, environment(me))) || !ob->is_character())
		return notify_fail("��Ҫ��˭��̣�\n");

	if( !living(ob) )
		return notify_fail("��....����Ȱ�" + ob->name() + "Ū����˵��\n");

	if(ob->query("race") != "����") return notify_fail("��ֻ�ܸ�����ѧ֪ʶ��\n");
        if( skill == "literate" && (int)me->query("potential") / 2 < learn_times )
                return notify_fail("���Ǳ�ܲ�����û�а취�ٳɳ��ˡ�\n");

	if( (int)me->query("potential") < learn_times )
		return notify_fail("���Ǳ�ܲ�����û�а취�ٳɳ��ˡ�\n");

	// HACK: recognize_apprentice takes care of the payment 
	// for literate.  We have to do this learn_times.
	for (i=0; i<learn_times; i++) {
	    if( !me->is_apprentice_of(ob) && !(ob->recognize_apprentice(me))  && !me->is_spouse_of(ob) ) {
		return	notify_fail( ob ->name() + reject_msg[random(sizeof(reject_msg))] );
	    }
	}

	if ( (string)me->query("family/family_name") == "������" 
	  && (string)ob->query("family/family_name") == "������"
	  && (string)me->query("gender") != "Ů��" 
	  && (int)me->query_int() < 20 + random(25) ) {
		slow_factor = 2; 
		slow_msg = "�������ã�";
	}
	else {
		slow_factor = 1;
		slow_msg = "";
	}

	if( !master_skill = ob->query_skill(skill, 1) )
	    return notify_fail("���������±����ұ���ѧ�ˡ�\n");

	notify_fail(ob->name() + "��Ը���������ܡ�\n");
	if( ob->prevent_learn(me, skill) ) return 0;

	my_skill = me->query_skill(skill, 1);
	if( my_skill >= master_skill )
		return notify_fail("�������ĳ̶��Ѿ�������ʦ���ˡ�\n");

	if (me->is_spouse_of(ob) )
	    if (my_skill >= master_skill - 20*(me->query("married_times")-1))
		return notify_fail(ob->name() + "�뵽�����ǰ" 
			+ me->query("spouse/title") 
			+ "��һ������Σ��е㲻��Ը���������ܡ�\n");
	    else if ( (ob->query("combat_exp") < 10000 
	    	       || me->query("combat_exp") < 10000 )
                        && ((string)SKILL_D(skill)->type() == "martial" || (string)SKILL_D(skill)->type() == "base_skill")  )
		return notify_fail("���Ƿ�ʵս���黹���㣬���ܻ��ഫ�����գ�\n");
               else if (skill == "qinqi-shuhua")
                        return notify_fail("�����黭ֻ����ʦ�����ڣ����ܷ��޼以�ഫ�ڣ�\n");
		
	notify_fail("����Ŀǰ��������û�а취ѧϰ���ּ��ܡ�\n");
	if (me->is_spouse_of(ob)) me->add_temp("mark/��", learn_times);
	if( !SKILL_D(skill)->valid_learn(me) ) return 0;
	if (me->is_spouse_of(ob)) me->add_temp("mark/��", -learn_times);

	gin_cost = 150 / (int)me->query("int");

	if( !my_skill ) {
	    gin_cost *= 2;
	    me->set_skill(skill,0);
	}

	printf("����%s����йء�%s�������ʡ�\n", ob->name(), to_chinese(skill));

	if( ob->query("env/no_teach") )
		return notify_fail("����" + ob->name() + "���ڲ���׼���ش�������⡣\n");

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
                if( ( (string)SKILL_D(skill)->type()=="martial" || (string)SKILL_D(skill)->type()=="base_skill" )
		&& my_skill > me->max_skill((int)me->query("combat_exp"))) {
			printf("Ҳ����ȱ��ʵս���飬���%s�Ļش������޷���ᡣ\n", ob->name() );
		} else {
		    if(skill_name = SKILL_D(skill)->query_skill_name(my_skill)) {
			if ( skill=="linji-zhuang" )
			    printf("������%s��ָ����%s�ԡ�%s���������ƺ�������ߡ�\n", 
				    ob->name(), slow_msg, skill_name);
			else
			    printf("������%s��ָ����%s�ԡ�%s����һ���ƺ���Щ�ĵá�\n", 
				    ob->name(), slow_msg, skill_name);
		    }
		    else
			printf("������%s��ָ����%s�ƺ���Щ�ĵá�\n", ob->name(), slow_msg);
//	    	    me->add("learned_points", learn_times);
		    me->add("potential", -learn_times);

		    tmp = 0;
		    for (i=0; i<learn_times; i++)  tmp += random(me->query_int());
	
		    me->improve_skill(skill, tmp/slow_factor);

		}
	} else {
		gin_cost = me->query("jing") > 0 ? (int)me->query("jing") : 0;
		write("�����̫���ˣ����ʲôҲû��ѧ����\n");
	}

	me->receive_damage("jing", gin_cost);

	return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ��learn|xue <ĳ��> <����> [����]
 
���ָ������������������й�ĳһ�ּ��ܵ��������⣬��Ȼ������̵�
������������ϵ�����������ߣ����㾭�����ַ�ʽѧϰ�����ļ���Ҳ
�����ܸ���������̵��ˣ�Ȼ����Ϊ����ѧϰ��ʽ�൱��һ�֡�����Ĵ��С���
���ѧϰ����˵����Ϥһ���¼������ķ�����

����ѧϰҲ��Ҫ����һЩ�����������ĵľ��������Լ�������ѧϰ�������
���йء�

�������ָ�� : apprentice, practice, skills, study, marry
HELP
        );
        return 1;
}
