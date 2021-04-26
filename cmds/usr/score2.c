// by Karlopex@sz
// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;
int q_long(string msg);
string tough_level(int power);
string string_m(string name, int a);
void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, skill_type, title, m_name, c_age, b_day, marry_t, marry_n, stzt;
	object weapon;
	int attack_points, dodge_points, parry_points,j, i, x, cnt;
        string pula, pulb, pulc, jbd, jszt, qzjx, nlzt, m_gxd, my_shen, my_exp, col;
	seteuid(getuid(me));

	if(!arg)
		ob = me;
	else
		ob = present(arg, environment(me));
	if (wizardp(me)) {
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("��Ҫ�쿴˭��״̬��\n");
	} else if (ob != me)
		return notify_fail("ֻ����ʦ�ܲ쿴���˵�״̬��\n");
	ob->update_age();
	my = ob->query_entire_dbase();
	col = ob->query("shen") == 0 ? HIG : (ob->query("shen")<0 ? HIB : HIR);
	my_shen = ob->query("shen") == 0 ? "δ��������" : ""+ob->query("shen")+"";
	my_exp = ob->query("combat_exp") > 0 ? ""+ob->query("combat_exp")+"" : "δ�뽭��";
	b_day = CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60);
	c_age = chinese_number(ob->query("age")) + "��" + (ob->query("month")?((ob->query("month")<10)?"��":"") +chinese_number(ob->query("month")) + "����":"");
	m_name = (!mapp(my["family"]))?"δ��ʦѧ��":((!(my["family"]["master_name"]))?"δ����ʦѧ��":my["family"]["master_name"]);
	m_gxd = (!mapp(my["menpai"]))?"�޹���":((!mapp(my["family"]) || !(my["family"]["master_name"]))?"��δ��ʦ":string_m(""+my["menpai"]["gxd"]+"", 10)+"��");
	title = (!mapp(my["family"]))?"��ͨ����":((!(my["family"]["family_name"]))?"��ͨ����":my["family"]["family_name"]);
	qzjx = ((ob->query("balance") <= 0) ? "û�л���":MONEY_D->money_str(ob->query("balance")));
	if (ob->is_married()){
		marry_t = my["spouse"]["title"];
		marry_n = my["spouse"]["name"];
	}else if( ob->query_temp("marriage") && (ob->query_temp("marriage/accept") || ob->query_temp("marriage/banquet"))){
		if (my["gender"] == ob->query_temp("marriage/accept")->query("gender")){
			marry_t = "ͬ����";
			if (ob->query_temp("marriage/accept"))
				marry_n = ob->query_temp("marriage/accept")->query("name");
			else marry_n = ob->query_temp("marriage/banquet")->query("name");
		}else{
			marry_t = (my["gender"] == "Ů��") ? "δ���":"δ����";
			marry_n = (my["gender"] == "Ů��") ? ob->query_temp("marriage/accept")->query("name"):ob->query_temp("marriage/banquet")->query("name");
		}
	}else{
		marry_t = "��  ��";
		marry_n = "����";
	}
	if( my["qi"]*100 / my["max_qi"]>=80 ) stzt = HIG + string_m("����", 6);
        else if( my["qi"]*100 / my["max_qi"]>=60 ) stzt = HIR + string_m("����", 6);
        else if( my["qi"]*100 / my["max_qi"]>=40 ) stzt = HIR + string_m("����", 6);
        else stzt = RED + string_m("����", 6);
	if( my["jingli"]*100 / my["max_jingli"]>=80 ) jszt = HIG + string_m("����", 6);
        else if( my["jingli"]*100 / my["max_jingli"]>=60 ) jszt = HIR + string_m("ƣ��", 6);
        else if( my["jingli"]*100 / my["max_jingli"]>=40 ) jszt = HIR + string_m("ƣ��", 6);
        else jszt = HIB + string_m("����", 6);

        if( objectp(weapon = ob->query_temp("weapon")))
		skill_type = weapon->query("skill_type");
	else
		skill_type = "unarmed";
	attack_points = COMBAT_D->skill_power(ob, skill_type, SKILL_USAGE_ATTACK);
	pula=tough_level(attack_points+ob->query_temp("apply/damage"));
	parry_points = COMBAT_D->skill_power(ob, "parry", SKILL_USAGE_DEFENSE);
	pulb=tough_level(parry_points);
	dodge_points = COMBAT_D->skill_power(ob, "dodge", SKILL_USAGE_DEFENSE);
	pulc=tough_level(dodge_points+ob->query_temp("apply/armor"));

	if ( userp(ob) ) line = sprintf(HBBLU+HIG+"��������������������"HIY"�����ݡ����˵���(%-4s����)"HIG"��������������������\n\n"+NOR, string_m(ob->query("language"), 4),);
	else line = sprintf(HBBLU+HIG+"������������������������"HIY" �����ݡ�NPC ���� "HIG"������������������������\n\n"+NOR);

	line += sprintf( BOLD "%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1) );
        line += sprintf(BLU"������������������������������������������������������������������\n"NOR);
        line += sprintf( HIC "������" NOR+CYN "[" HIW "%3d" + NOR+CYN +"/" WHT "%3d" NOR+CYN "]��" HIC "���ԣ�" NOR+CYN "[" HIW  "%3d" + NOR+CYN +"/" WHT "%3d" NOR+CYN "]��" HIC "���ǣ�" NOR+CYN "[" HIW  "%3d" + NOR+CYN +"/" WHT "%3d" NOR+CYN "]��" HIC "����" NOR+CYN "[" HIW  "%3d" + NOR+CYN +"/" WHT "%3d" NOR+CYN "]\n\n" NOR , 
                ob->query_str(), ob->query("str"), ob->query_int(), ob->query("int"), ob->query_con(), ob->query("con"), ob->query_dex(), ob->query("dex"));
        line += sprintf("���䣺" NOR+CYN "[" HIG "%22s" NOR+CYN "]��" NOR, string_m(c_age, 22));
	line += sprintf("������" NOR+CYN "[" HIG "%26s" CYN "]\n" NOR, string_m(b_day, 26));		
	line += sprintf("�Ա�" NOR+CYN "[" HIG "%6s" NOR+CYN "]��" NOR, string_m(ob->query("gender"), 6));
	line += sprintf("���壺" NOR+CYN "[%6s" NOR+CYN "]��" NOR, stzt);
	line += sprintf("����" NOR+CYN "[%6s" NOR+CYN "]��" NOR, jszt);
	line += sprintf("%6s��" NOR+CYN "[" HIG "%8s" NOR+CYN "]\n" NOR, marry_t, string_m(marry_n, 8) );
	line += sprintf("Ǯׯ���" NOR+CYN "[" HIY "%54s" NOR+CYN "]\n" NOR, string_m(qzjx, 54));
	line += sprintf("�������壺" NOR+CYN "[" HIG );
	if ( ob->is_jiebaied() )
	{
		ob->jiebai_check();
		cnt = ob->jiebai_cnt();
		if (cnt != 0)
		{
			for( i=0; i<cnt; i++)
			{
				j++;
				line += sprintf( "%18s%s", string_m(ob->jiebai_list(i), 18),(j != cnt)? ((j%3==0) ?NOR+CYN "]\n����������[" HIG:""):"" );
				}	
			if (j%3 == 0) line += sprintf( NOR+CYN "]\n\n" NOR );	
			if (j%3 == 1) line += sprintf( "%36s" NOR+CYN "]\n\n" NOR, "" );	
			if (j%3 == 2) line += sprintf( "%18s" NOR+CYN "]\n\n" NOR, "" );	
		}else line += sprintf( "%54s" NOR+CYN "]\n\n" NOR, string_m("��Ŀǰû�н�ݵ����", 54) );
	}else line += sprintf( "%54s" NOR+CYN "]\n\n" NOR, string_m("��Ŀǰû�н�ݵ����", 54) );

	line += sprintf( HIY "���ɣ�" NOR+CYN "[" HIG "%12s" NOR+CYN "]�� "NOR, string_m(title, 12));
	line += sprintf( HIY "ʦ�У�" NOR+CYN "[" HIG "%12s" NOR+CYN "]�� "NOR, string_m(m_name, 12));
	line += sprintf( HIY "���ף�" NOR+CYN "[" HIG "%12s" NOR+CYN "]\n"NOR, string_m(m_gxd, 12));
	line += sprintf( HIC "���飺" NOR+CYN "[" HIG "%12s" NOR+CYN "]�� "HIC "%6s" NOR+CYN "[" + col + "%12s" NOR+CYN "]�� ", string_m(my_exp, 12), ob->query("shen") == 0 ? "������" : (ob->query("shen")<0 ? BLU"а����"NOR : HIR"������"NOR), string_m(my_shen, 12));
       	line += sprintf( HIC "����: "NOR+CYN "[" HIG "%12s" NOR+CYN "]\n"NOR,userp(ob) ? string_m(FINGER_D->age_string(my["mud_age"]), 12):string_m("NPC�޴���", 12));
	line += sprintf( HIW "������" NOR+CYN "[%-12s" NOR+CYN "]�� "HIW "������" NOR+CYN "[%-12s" NOR+CYN "]�� "HIW "������" NOR+CYN "[%-12s" NOR+CYN "]\n\n"NOR, string_m(pula, 12), string_m(pulb, 12), string_m(pulc, 12));
	line += sprintf( HIB "ɱ�ˣ�" NOR+CYN "[" HIG "%20sλ" NOR+CYN "]��" HIB "ɱ����ң�" NOR+CYN "[" HIG "%20sλ" NOR+CYN "]\n" NOR,
		chinese_number(my["MKS"] + my["PKS"]), chinese_number(my["PKS"]));
	line += sprintf( HIB "������" NOR+CYN "[" HIG "%20sλ" NOR+CYN "]��" HIB "��Ч������" NOR+CYN "[" HIG "%20s��" NOR+CYN "]\n" NOR,
	        chinese_number(my["death_count"]), chinese_number(my["death_times"]));
	if (my["last_pk"] && my["last_death"])
		line += sprintf("�����һ���Ƕ� "HIG"%20s"NOR" ʹ��ɱ�֡�\n�����һ���Ǳ� "HIG"%20s"NOR" ɱ����\n\n", string_m(my["last_pk"], 20), string_m(my["last_death"], 20));
	else if (!my["last_pk"] && my["last_death"])
		line += sprintf("��δ�����ʹ��ɱ�֣������һ���Ǳ� "HIG"%20s"NOR" ɱ����\n\n", string_m(my["last_death"], 20));
	else if (my["last_pk"] && !my["last_death"])
		line += sprintf("�����һ���Ƕ� "HIG"%20s"HIG" ʹ��ɱ�֣����δ�����ɱ������\n\n", string_m(my["last_pk"], 20));
	else line += "\n";
        line += sprintf( HIY "���ɣ�" NOR+CYN "[" HIG "%12s" NOR+CYN "]�� " ,
                 ob->query("newjob/country") ? string_m(ob->query("newjob/country"), 12):string_m("δ����", 12) );
        line += sprintf( HIY "��ҵ��" NOR+CYN "[" HIG "%12s" NOR+CYN "]�� " ,
                 ob->query("newjob/estate") ? string_m(ob->query("newjob/estate"), 12):string_m("δ����", 12) );
        line += sprintf( HIY "סլ��" NOR+CYN "[" HIG "%12s" NOR+CYN "]\n" NOR ,
                 ob->query("newjob/dwelling") ? string_m(ob->query("newjob/dwelling"), 12):string_m("¶�޽�ͷ", 12) );
        line += sprintf( HIY "ְҵ��" NOR+CYN "[" HIG "%12s" NOR+CYN "]�� " ,
                 ob->query("newjob/jobtitle") ? string_m(ob->query("newjob/jobtitle"), 12):string_m("δ����", 12) );
        line += sprintf( HIY "�ȼ���" NOR+CYN "[" HIG "%12s" NOR+CYN "]�� " ,
                 ob->query("newjob/level") ? string_m(ob->query("newjob/level"), 12):string_m("δ����", 12) );
        line += sprintf( HIY "���룺" NOR+CYN "[" HIG "%12s" NOR+CYN "]\n" NOR,
                 ob->query("newjob/income") ? string_m(chinese_number(ob->query("newjob/income")), 12):string_m("δ����", 12) );
	write(line);
	return 1;
}


string tough_level(int power)
{

	int lvl, rawlvl;

        string *tough_level_desc = ({
BLU "����һ��" NOR,BLU "��������" NOR,BLU "����ҳ�" NOR,BLU "��ѧէ��" NOR,BLU "����ǿǿ" NOR,
BLU "�����ž�" NOR,BLU "����é®" NOR,BLU "��֪һ��" NOR,BLU "����ͨͨ" NOR,BLU "ƽƽ����" NOR,
GRN "ƽ������" NOR,GRN "��ͨƤë" NOR,GRN "��������" NOR,GRN "������" NOR,GRN "����С��" NOR,
GRN "����С��" NOR,GRN "������Ⱥ" NOR,GRN "�������" NOR,GRN "�������" NOR,GRN "�ڻ��ͨ" NOR,
CYN "�������" NOR,CYN "¯����" NOR,CYN "��Ȼ����" NOR,CYN "���д��" NOR,CYN "���д��" NOR,
CYN "��Ȼ��ͨ" NOR,CYN "�������" NOR,CYN "�޿�ƥ��" NOR,CYN "����Ⱥ��" NOR,CYN "����似" NOR,
HIB "�����뻯" NOR,HIB "��ͬ����" NOR,HIB "����Ⱥ��" NOR,HIB "�Ƿ��켫" NOR,HIB "�����ױ�" NOR,
HIB "��������" NOR,HIB "һ����ʦ" NOR,HIB "�������" NOR,HIB "�񹦸���" NOR,HIB "������˫" NOR,
MAG "��������" NOR,MAG "���춯��" NOR,MAG "������" NOR,MAG "������ʥ" NOR,MAG "�������" NOR,
MAG "��ǰ����" NOR,MAG "���˺�һ" NOR,MAG "��ز�¶" NOR,MAG "��ɲ�" NOR,WHT "��豹���" NOR

});

	if(power<0) power=0;
	rawlvl = (int) pow( (float) 1.0 * power, 0.211);
        lvl = to_int(rawlvl);
        
        if( lvl >= sizeof(tough_level_desc) )
            lvl = sizeof(tough_level_desc)-1;

        return tough_level_desc[lvl];
}
string string_m(string name, int a)
{
	int s, x = q_long(name);
	string blank = "                                                    ";
	s = ((a-x)/2)-1;
	if (x == a) return name;
	else if (x < a) return blank[0..s] + name + blank[0..s];
	else return "δ֪����";
}
int q_long(string msg){
        msg = replace_string(msg, BLK, "");
        msg = replace_string(msg, RED, "");
        msg = replace_string(msg, GRN, "");
        msg = replace_string(msg, YEL, "");
        msg = replace_string(msg, BLU, "");
        msg = replace_string(msg, MAG, "");
        msg = replace_string(msg, CYN, "");
        msg = replace_string(msg, WHT, "");
        msg = replace_string(msg, HIR, "");
        msg = replace_string(msg, HIG, "");
        msg = replace_string(msg, HIY, "");
        msg = replace_string(msg, HIB, "");
        msg = replace_string(msg, HIM, "");
        msg = replace_string(msg, HIC, "");
        msg = replace_string(msg, HIW, "");
        msg = replace_string(msg, NOR, "");
	return strlen(msg);
}
int help(object me)
{
	write(@HELP
ָ���ʽ : score
           score <��������>                   (��ʦר��)

���ָ�������ʾ��(��)��ָ������(������)�Ļ������ϡ�
�������ϵ��趨����� 'help setup'��

see also : hp
HELP
    );
    return 1;
}
