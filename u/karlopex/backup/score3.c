// by momo 11/1 . 2001
// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;
string bar_string = "��������������������������";
string blank_string = "��������������������������";
string blank_string3 = "��������������������������";
string blank_string2 = "������������������������";
string display_attr(int gift, int value);
string status_color(int current, int max);
string money_str(int amount);
string tough_level(int power);
string tribar_graph(int val, int eff, int max, string color);
string tribar_graph2(int val, int eff, int max, string color);
string tribar_graph3(int a);
string string_m(string name, int a);
void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line, skill_type, title, m_name, c_age, b_day, marry_t, marry_n, stzt;
	object weapon;
	int attack_points, dodge_points, parry_points,jings, qis, j, i, x, cnt;
        string pula, pulb, pulc, jbd, jszt, qzjx;
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
	b_day = CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60);
	c_age = chinese_number(ob->query("age")) + "��" + (ob->query("month")?((ob->query("month")<10)?"��":"") +chinese_number(ob->query("month")) + "����":"");
	m_name = (!mapp(my["family"]))?"��δ����ʦѧ��":((!(my["family"]["master_name"]))?"��δ����ʦѧ��":my["family"]["master_name"] + "(" +capitalize(my["family"]["master_id"]) + ")");
	title = (!mapp(my["family"]))?"��ͨ����":((!(my["family"]["family_name"]))?"��ͨ����":my["family"]["family_name"]);
	qzjx = ((ob->query("balance") <= 0) ? "û�л���":money_str(ob->query("balance")));
	jings = (my["eff_jing"]*13/my["max_jing"])*2;
	qis = (my["eff_qi"]*13/my["max_qi"])*2;
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
        line = sprintf(HBBLU+HIY+"                  �����ݡ����˵���(%-4s����)                      \n\n"+NOR, ob->query("language"),);
	line += sprintf( BOLD "  %s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1) );
        line += sprintf(BLU"������������������������������������������������������������������\n"NOR);
        line += sprintf("���䣺" NOR+CYN "[" HIG "%22s" NOR+CYN "]��" NOR, string_m(c_age, 22));
	line += sprintf("������" NOR+CYN "[" MAG "%26s" CYN "]\n" NOR, string_m(b_day, 26));		
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
	line += sprintf( HIC "���ɣ�" NOR+CYN "[" HIG "%12s" NOR+CYN "]��"NOR, string_m(title, 12));
	line += sprintf( HIC "ʦ�У�" NOR+CYN "[" HIG "%36s" NOR+CYN "]\n\n"NOR, string_m(m_name, 36));

        line += sprintf( HIC "������" NOR+CYN "[" HIW "%3d" + NOR+CYN +"/" WHT "%3d" NOR+CYN "]��" HIC "���ԣ�" NOR+CYN "[" HIW  "%3d" + NOR+CYN +"/" WHT "%3d" NOR+CYN "]��" HIC "���ǣ�" NOR+CYN "[" HIW  "%3d" + NOR+CYN +"/" WHT "%3d" NOR+CYN "]��" HIC "����" NOR+CYN "[" HIW  "%3d" + NOR+CYN +"/" WHT "%3d" NOR+CYN "]\n\n" NOR , 
                ob->query_str(), ob->query("str"), ob->query_int(), ob->query("int"), ob->query_con(), ob->query("con"), ob->query_dex(), ob->query("dex"));
        if( my["max_jing"] >= my["eff_jing"])
		line += sprintf( HIC "��  "NOR"��%-26s", tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"])) + tribar_graph3(jings));
	else
		line += sprintf( HIC "��  "NOR"��%-26s" , tribar_graph2(my["jing"], my["max_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"]))+ tribar_graph3(jings));

	if( my["max_jingli"] > 0 )
		line += sprintf( HIC "������"NOR"��%-26s\n"NOR, tribar_graph(my["jingli"], my["max_jingli"], my["max_jingli"], status_color(my["jingli"], my["max_jingli"])));
	else
		line += sprintf( HIC "������"NOR"��%-26s\n",tribar_graph2(my["jingli"], my["max_jingli"], my["max_jingli"], status_color(my["jingli"], my["max_jingli"])));

	if( my["max_qi"] >= my["eff_qi"])
		line += sprintf( HIC "��  "NOR"��%-26s", tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));
	else	
		line += sprintf( HIC "��  "NOR"��%-26s", tribar_graph2(my["qi"], my["max_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));

	if( my["max_neili"] > 0 )
		line += sprintf( HIC "������"NOR"��%-26s\n"NOR, tribar_graph(my["neili"], my["max_neili"], my["max_neili"], status_color(my["neili"], my["max_neili"])));
	else
		line += sprintf( HIC "������"NOR"��%-26s\n", tribar_graph3(-1));

	if( ob->max_food_capacity() > 0 )
		line += sprintf( HIC "ʳ��"NOR"��%-26s", tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL));
	else
		line += sprintf( HIC "ʳ��"NOR"��%-26s",tribar_graph2(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL));
	
	if( ob->max_water_capacity() > 0 )
		line += sprintf( HIC "����ˮ"NOR"��%-26s\n"NOR , tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN));
	else
		line += sprintf( HIC "����ˮ"NOR"��%-26s\n"NOR,tribar_graph2(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), YEL));
	if( my["max_potential"] > 0 )
		line += sprintf( HIC "Ǳ��"NOR"��%-26s" , tribar_graph(my["potential"], my["max_potential"], my["max_potential"], GRN));
	else
		line += sprintf( HIC "Ǳ��"NOR"��%-26s");
         	line += sprintf( HIC "����Ϸʱ��"NOR": "HIM"%-22s\n",string_m(FINGER_D->age_string(my["mud_age"]), 22));
	line += sprintf( HIC "���飺" NOR+CYN "[" HIG "%-24d" NOR+CYN "]��"HIC "%2s��" NOR+CYN "[" HIG "%-24d" NOR+CYN "]\n\n", ob->query("combat_exp"), ob->query("shen")<0 ? BLU"а��"NOR : HIR"����"NOR, ob->query("shen"));
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

	line += sprintf( HIW "��������" NOR+CYN "[%-10s" NOR+CYN "]�� "HIW "��������" NOR+CYN "[%-10s" NOR+CYN "]�� "HIW "��������" NOR+CYN "[%-10s" NOR+CYN "]\n\n"NOR, pula, pulb, pulc);
          
	line += sprintf( HIB "ɱ�ˣ�" NOR+CYN "[" RED "%22sλ" NOR+CYN "]��" HIB "ɱ����ң�" NOR+CYN "[" HIR "%18sλ" NOR+CYN "]\n" NOR,
		chinese_number(my["MKS"] + my["PKS"]), chinese_number(my["PKS"]));
	line += sprintf( HIB "������" NOR+CYN "[" RED "%22sλ" NOR+CYN "]��" HIB "��Ч������" NOR+CYN "[" HIR "%18s��" NOR+CYN "]\n" NOR,
	        chinese_number(my["death_count"]), chinese_number(my["death_times"]));
	if (my["last_pk"] && my["last_death"])
		line += sprintf(HIR "�����һ���Ƕ� "HIR"%20s"HIR" ʹ��ɱ�֡�\n�����һ���Ǳ� "HIR"%20s"HIR" ɱ����\n\n", string_m(my["last_pk"], 20), string_m(my["last_death"], 20));
	else if (!my["last_pk"] && my["last_death"])
		line += sprintf(HIR "��δ�����ʹ��ɱ�֣������һ���Ǳ� "HIR"%20s"HIR" ɱ����\n\n", string_m(my["last_death"], 20));
	else if (my["last_pk"] && !my["last_death"])
		line += sprintf(HIR "�����һ���Ƕ� "HIR"%20s"HIR" ʹ��ɱ�֣����δ�����ɱ������\n\n", string_m(my["last_pk"], 20));

        line += sprintf( HIY "���ɣ�" NOR+CYN "[" HIG "%12s" NOR+CYN "]��" ,
                 ob->query("newjob/country") ? string_m(ob->query("newjob/country"), 12):string_m("δ����", 12) );
        line += sprintf( HIY "��ҵ��" NOR+CYN "[" HIG "%13s" NOR+CYN "]��" ,
                 ob->query("newjob/estate") ? string_m(ob->query("newjob/estate"), 12):string_m("δ����", 12) );
        line += sprintf( HIY "סլ��" NOR+CYN "[" HIG "%13s" NOR+CYN "]\n" NOR ,
                 ob->query("newjob/dwelling") ? string_m(ob->query("newjob/dwelling"), 12):string_m("¶�޽�ͷ", 12) );
        line += sprintf( HIY "ְҵ��" NOR+CYN "[" HIG "%12s" NOR+CYN "]��" ,
                 ob->query("newjob/jobtitle") ? string_m(ob->query("newjob/jobtitle"), 12):string_m("δ����", 12) );
        line += sprintf( HIY "�ȼ���" NOR+CYN "[" HIG "%13s" NOR+CYN "]��" ,
                 ob->query("newjob/level") ? string_m(ob->query("newjob/level"), 12):string_m("δ����", 12) );
        line += sprintf( HIY "���룺" NOR+CYN "[" HIG "%13s" NOR+CYN "]\n" NOR,
                 ob->query("newjob/income") ? string_m(chinese_number(ob->query("newjob/income")), 12):string_m("δ����", 12) );
	write(line);
	return 1;
}


string display_attr(int gift, int value)
{
	if( value > gift ) return sprintf( HIY "%6s" NOR, chinese_number(value) );
	else if( value < gift ) return sprintf( CYN "%6s" NOR, chinese_number(value) );
	else return sprintf("%6s", chinese_number(value));
}

string status_color(int current, int max)
{
	int percent;

	if( max ) percent = current * 100 / max;
	else percent = 100;

	if( percent > 100 ) return HIC;
	if( percent >= 90 ) return HIG;
	if( percent >= 60 ) return HIY;
	if( percent >= 30 ) return YEL;
	if( percent >= 10 ) return HIR;
	return HIB;
}

string money_str(int amount)
{
        // returns a chinese string of `amount` of money
        string output;

        if (amount / 10000) {
                output = chinese_number(amount / 10000) + "���ƽ�";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "������";
                amount %= 100;
        }
        if (amount)
                return output + chinese_number(amount) + "��ͭ��";
        return output;
}

string tough_level(int power)
{

	int lvl, rawlvl;
	string pul;
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
        power = power*2;
	rawlvl = (int) pow( (float) 1.0 * power, 0.211);
        lvl = to_int(rawlvl);
        
        if( lvl >= sizeof(tough_level_desc) )
            lvl = sizeof(tough_level_desc)-1;
        pul = tough_level_desc[lvl];
        pul = replace_string( pul, tough_level_desc[lvl][5..<8], string_m(tough_level_desc[lvl][5..<8], 10) );
        return pul;
}
string tribar_graph(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*13/max)*2-1]
		+ ((eff > val) ? blank_string[(val*13/max)*2..(eff*13/max)*2-1] : "") + NOR;
}
string tribar_graph2(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*13/max)*2-1]
		+ ((eff > val) ? blank_string2[(val*13/max)*2..(eff*13/max)*2-1] : "") + NOR;
}
string tribar_graph3(int a)
{
	if (a == -1) return BLU + blank_string3 + NOR;
	else return BLU + blank_string3[0..(25-a)] + NOR;
}
string string_m(string name, int a)
{
	int s, x = strlen(name);
	string blank = "                                                    ";
	s = ((a-x)/2)-1;
	if (x == a) return name;
	else if (x < a) return blank[0..s] + name + blank[0..s];
	else return "δ֪����";
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
