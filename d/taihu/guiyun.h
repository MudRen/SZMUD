// Code of ShenZhou
#include <ansi.h>
void init()
{
	object me = this_player();
	int score, skill, age;

	if ( me->query("age") >= 30 || random(me->query_kar()) < 30)
		return 0;
	if ( me->query("family/master_id") != "lu chengfeng" 
         && me->query("family/master_id") != "qu lingfeng")
		return 0;


	age = me->query("age") - 14;
	skill = (me->query_skill("force") + me->query_skill("dodge") 
		+ me->query_skill("strike") + me->query_skill("qimen-dunjia"))/4;
	skill *= me->query("combat_exp")/1000;
	score = skill/age;

	if (score < 1000) return 0;
	
	remove_call_out("recruit_ob");
	call_out("recruit_ob", 150, me);
	tell_object(me, CYN"���������е�Ź֣��ƺ����˸��棿\n"NOR);
	log_file("Taohua", sprintf("%s(%s)��%s triggered Huang to recruit��\n",
                me->query("name"), getuid(me), ctime(time())));
	add_action("check_score", "check_score");
}

void recruit_ob(object me)
{
	object ob, *obj;
	int i, j = 0;

	obj = all_inventory(environment(me));
        for(i=0; i<sizeof(obj); i++)
        {
                if ((string)obj[i]->query("race") == "����")
		j++;
	}
	if (j > 1) return;

	if (!me) return;

	ob = new(CLASS_D("taohua/huang"));
	me->start_busy(1);
	ob->move(environment(me));

	message_vision("$Nǰ��ͻȻ������һ�ˣ���ĸ��ݣ�����ɫ���ۣ���ɫ�Ź�֮�������������ƺ�����
΢΢ת��������֮�⣬����ڱǣ����Խ�Ӳ��ľʯ��ֱ��һ������ͷװ�ڻ��˵������ϡ�\n\n", me);
	message_vision("$Nһ��֮�£���ʱһ�������ӱ�����ֱ��������Ŀ�������������ഥ���㶼�����ٿ�����ʱ��
ͷת����������Ȼ������Ī���������ʦүү�������д��ŵ��һ������� æ��ǰ��������
�Ŀ����ĸ�ͷ��˵���������ߵ��ʦ�档����ҩʦ���������ˣ����������������ȴ������
ץס$N����һ�ᣬ���Ʊ���$N��ͷ���¡�����\n", me);
	message_vision("$Nһ�����������ϸ�룬�Ͻ����μ�����ʹ��һ�С������ڿա���������ͬΪ�������������Ʈ��һ�����ࡣ\n\n", me);
	message_vision("��ҩʦ΢һ㶣�����һ������"+RANK_D->query_rude(me)+"ȴ�м������ʣ��Ҿͳ�ȫ��ɡ�\n", me);
	
	message_vision("\n$N��Ҫ��$nΪ���ӡ�\n", ob, me);
        tell_object(me, YEL "�����Ը���" + me->name() + "Ϊʦ������ apprentice ָ�\n" NOR);
	me->set_temp("huang_recr", 1);
	log_file("Taohua", sprintf("%s(%s)��%s be attempted to recruit by Huang��\n",
                me->query("name"), getuid(me), ctime(time())));
	call_out("finish_recr", 30, me, ob);
}
void finish_recr(object me, object ob)
{
	if (me->query("family/master_id") != "huang yaoshi"){
	message_vision("$N��Цһ����"+RANK_D->query_rude(me)+"��Ȼ�м��ֳ����ӡ�˵��ƮȻ��ȥ��\n", ob);
	me->delete_temp("huang_recr");
	destruct(ob);
	}
	return;
}
//You can call this function to check a player's score.
int check_score(string who)
{
	object player,me;
	int age, skill, score;	

	player = this_player();
	if (!wizardp(player))
		return notify_fail("ʲô��\n");
	me = find_player(who);

	if (!me) return 0;

	age = me->query("age") - 14;
        skill = (me->query_skill("force") + me->query_skill("dodge")
                + me->query_skill("strike") + me->query_skill("qimen-dunjia"))/3;
        skill *= me->query("combat_exp")/1000;
        score = skill/age;
	return score;
}
