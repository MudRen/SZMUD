// by momo 11/1 . 2001
// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;
string bar_string = "������������������������";
string blank_string = "������������������������";
string blank_string3 = "������������������������";
string blank_string2 = "������������������������";
string display_attr(int gift, int value);
string status_color(int current, int max);
string money_str(int amount);
string tough_level(int power);
string tribar_graph(int val, int eff, int max, string color);
string tribar_graph2(int val, int eff, int max, string color);
string tribar_graph3(int a);
void create() { seteuid(ROOT_UID); }

int main(object me, string arg)
{
	object ob;
	mapping my;
	string line , skill_type;
	object weapon;
	int attack_points, dodge_points, parry_points,jings, qis, j, i, x, cnt;
        string pula,pulb,pulc,jbd;
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
	my = ob->query_entire_dbase();
	jings = (my["eff_jing"]*12/my["max_jing"])*2;
	qis = (my["eff_qi"]*12/my["max_qi"])*2;
	if ( userp(ob) ) line = sprintf(HBBLU"��������������������"HIY"�����ݡ����˵���(%-4s����)"HIG"��������������������\n\n"+NOR, string_m(my["language"], 4),);
	line += sprintf( BOLD "  %s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1) );
	ob->update_age();
	
        line += sprintf( YEL "������������������������������������������������������������������\n" NOR );
        line += sprintf( YEL "��"HIR" �� �� �� �� �� ��                                            "NOR+YEL"��\n" NOR );
        line += sprintf( YEL "�ǩ����������������������������������ש���������������������������\n" NOR );
        line += sprintf( YEL "��" HIY "�����䡿" NOR "%6.6s��%-12.12s      " YEL "��" NOR ,
 		chinese_number(ob->query("age")),
		ob->query("month")?"��" +chinese_number(ob->query("month")) + "����":"");
		
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

      line += sprintf( HIW "����������" NOR "      %15s  " YEL "��\n" NOR ,
		pula);

         line += sprintf( YEL "��" HIY "���Ա�" NOR "%-26.8s" YEL "��" NOR ,
                    ob->query("gender"));
                                        
      line += sprintf( HIW "����������" NOR "      %15s  " YEL "��\n" NOR ,
                pulb);

      line += sprintf( YEL "��" HIY "��������" MAG "%-22.22s" NOR+YEL "    ��" NOR ,
                CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );

       line += sprintf( HIW "����������" NOR "      %15s  " YEL "��\n" NOR ,
                pulc);
	line += sprintf( YEL "��                          ���������ߩ���������������������������\n" NOR,);      
      if( mapp(my["family"]) )
  {
	if( my["family"]["family_name"] )
	 line += sprintf( YEL "��" HIW "�����ɡ�" NOR "%-18.8s" YEL "��" NOR,
				my["family"]["family_name"] );
        else  
         line += sprintf( YEL "��" HIW "�����ɡ�" NOR "��ͨ����          " YEL "��" NOR );
  }
  else  
         line += sprintf( YEL "��" HIW "�����ɡ�" NOR "��ͨ����          " YEL "��" NOR );

        line += sprintf( HIY "��������" HIW "%3d|%3d    " HIY "�����ԡ�" HIW "%3d|%3d" NOR+YEL "��\n" NOR , 
                ob->query_str(),
                ob->query("str"), 
		ob->query_int(),
		ob->query("int"));

      if( mapp(my["family"]) )
  {
	if( my["family"]["master_name"] )
	 line += sprintf( YEL "��" HIW "��ʦ�С�" NOR "%-18.8s" YEL "��" NOR,
				my["family"]["master_name"] );
        else
         line += sprintf( YEL "��" HIW "��ʦ�С�" NOR "�㻹û�а�ʦ      " YEL "��" NOR );
  }
  else  
         line += sprintf( YEL "��" HIW "��ʦ�С�" NOR "�㻹û�а�ʦ      " YEL "��" NOR );
        line += sprintf( HIY "�����ǡ�" HIW "%3d|%3d    " HIY "������" HIW "%3d|%3d" NOR+YEL "��\n" NOR , 		
		ob->query_con(),
                ob->query("con"), 
		ob->query_dex(),
		ob->query("dex"));
	if (ob->is_married())
	line += sprintf(YEL "��" HIW "��%s��" NOR "%-18.8s" YEL "��������������������������������������\n" NOR , my["spouse"]["title"],my["spouse"]["name"] );
	else if( ob->query_temp("marriage") && (ob->query_temp("marriage/accept") || ob->query_temp("marriage/banquet")))
        line += sprintf(YEL "��" HIW "��%s��" NOR "%-16.8s" YEL "��������������������������������������\n" NOR ,
			my["gender"]=="Ů��"?"δ���":"δ����",
                        my["gender"]=="Ů��"?ob->query_temp("marriage/accept")->query("name"):ob->query_temp("marriage/banquet")->query("name"));
	else line += sprintf( YEL "��" HIW "��������" NOR "����              " YEL "��������������������������������������\n" NOR );
	line += sprintf( YEL "��" HIW "�����塿"NOR);
	if ( ob->is_jiebaied() )
	{
		ob->jiebai_check();
		cnt = ob->jiebai_cnt();
		if (cnt != 0)
		{
			for( i=0; i<cnt; i++)
			{
				j++;
				line += sprintf( "%-18s%s" ,ob->jiebai_list(i),(j != cnt)? ((j%3==0) ? YEL "��\n����������" NOR:""):"" );
				}	
			if (j%3 == 0) line += sprintf( YEL "��\n" NOR );	
			if (j%3 == 1) line += sprintf( YEL "%36s��\n" NOR,"" );	
			if (j%3 == 2) line += sprintf( YEL "%18s��\n" NOR,"" );	
                }else line += sprintf( "��û�н�ݵ����%38s"YEL"��\n" NOR,"" );
	}else{
                line += sprintf( "δ����%48s"YEL"��\n" NOR,"" );
	}
	if (ob->query("balance") <= 0)
		line += sprintf( YEL "��" HIW "��Ǯׯ���" HIY "û�л���                                          " NOR+YEL "��\n" NOR );
	else
         {
         	line += sprintf ( YEL "��"  HIW "��Ǯׯ���" NOR );
         	line += sprintf ("%-50.50s",
         	money_str(ob->query("balance")));
         	line += sprintf ( NOR+YEL "��\n" NOR );
         	}
	line += sprintf( YEL "��                                                              ��\n" NOR );
	line += sprintf( YEL "��" HIG "�����顿" NOR "%-20d \t" YEL,ob->query("combat_exp"));
	line += sprintf( HIG " ��%s��" NOR "%-18d" YEL "     ��\n" NOR ,
                 ob->query("shen")<0?"а��":"����",
	         ob->query("shen") );
	line += sprintf( YEL "��                                                              ��\n" NOR );
        if( my["max_jing"] >= my["eff_jing"])
		line += sprintf( YEL "��" HIC" ��  "NOR"��%-24s ", tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"])) + tribar_graph3(jings));
	else
		line += sprintf( YEL "��" HIC" ��  "NOR"��%-24s " , tribar_graph2(my["jing"], my["max_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"]))+ tribar_graph3(jings));

	if( my["max_jingli"] > 0 )
		line += sprintf( HIC "����"NOR"��%-24s"+ NOR+YEL+"��\n"NOR, tribar_graph(my["jingli"], my["max_jingli"], my["max_jingli"], status_color(my["jingli"], my["max_jingli"])));
	else
		line += sprintf( HIC "����"NOR"��%-24s\n");

	if( my["max_qi"] >= my["eff_qi"])
		line += sprintf( YEL "��" HIC" ��  "NOR"��%-24s ", tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));
	else	
		line += sprintf( YEL "��" HIC" ��  "NOR"��%-24s ", tribar_graph2(my["qi"], my["max_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));

	if( my["max_neili"] > 0 )
		line += sprintf( HIC "����"NOR"��%-24s"+ NOR+YEL+"��\n"NOR, tribar_graph(my["neili"], my["max_neili"], my["max_neili"], status_color(my["neili"], my["max_neili"])));
	else
		line += sprintf( HIC "����"NOR"��%-24s\n");

	if( ob->max_food_capacity() > 0 )
		line += sprintf( YEL "��" HIC" ʳ��"NOR"��%-24s ", tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL));
	else
		line += sprintf( YEL "��" HIC" ʳ��"NOR"��%-24s ");
	
	if( ob->max_water_capacity() > 0 )
		line += sprintf( HIC "��ˮ"NOR"��%-24s"+ NOR+YEL+"��\n"NOR , tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN));
	else
		line += sprintf( HIC "��ˮ"NOR"��%-24s\n");
	if( my["max_potential"] > 0 )
		line += sprintf( YEL "��" HIC" Ǳ��"NOR"��%-24s " , tribar_graph(my["potential"], my["max_potential"], my["max_potential"], GRN));
	else
		line += sprintf( YEL "��" HIC" Ǳ��"NOR"��%-24s ");
         	line += sprintf( HIC "��Ϸʱ��"NOR": "HIM"%-20s"NOR+YEL"��\n",FINGER_D->age_string(my["mud_age"]));
          
	line += sprintf( YEL "�ǩ���������������������������������������������������������������\n" NOR );
        line += sprintf( YEL "��"HIR" �� �� �� �� ¼ ��                                            "NOR+YEL"��\n" NOR );
        line += sprintf( YEL "�ǩ���������������������������������������������������������������\n" NOR );        

	if (my["MKS"] + my["PKS"])
	{        
		line += sprintf( YEL "��" HIB "��ɱ�ˡ�" NOR "%12.12s" NOR "λ        ", 
			chinese_number(my["MKS"] + my["PKS"]));
		line += my["PKS"]?sprintf( HIB "��ɱ����ҡ�" NOR "%12.12sλ      " YEL "��\n" NOR ,
	                chinese_number(my["PKS"])): HIB "��ɱ����ҡ�" NOR "          ��λ      " YEL "��\n" NOR ;
	}else 
 		line += ( YEL "��" HIB "��ɱ�ˡ�" NOR "          ��λ        " HIB "��ɱ����ҡ�" NOR "          ��λ      "YEL "��\n" NOR );
	//line += sprintf(YEL "��" CYN " ���δɱ��������ҡ�                                         " NOR+YEL "��\n");
	if (my["death_count"] > 0)
	line += sprintf( YEL "��" HIB "��������" NOR "%12.12s��        " HIB "����Ч������" NOR "%12.12s��      " YEL "��\n" NOR ,
	        chinese_number(my["death_count"]), chinese_number(my["death_times"]));
	else
        line += ( YEL "��" HIB "��������" NOR "          ���        " HIB "����Ч������" NOR "          ���      "YEL "��\n" NOR );
	if (my["last_pk"])
	line += sprintf(YEL "��" HIR " �����һ���Ƕ� "HIR"%-20s"HIR" ʹ��ɱ�֡�               " NOR+YEL "��\n",my["last_pk"]);
	if (my["last_death"])
	line += sprintf(YEL "��" HIR " �����һ���Ǳ� "HIR"%-20s"HIR" ɱ����                   " NOR+YEL "��\n",my["last_death"]);
	//line += sprintf(YEL "��" CYN " ���δ���������ֱ��ɱ����                                   " NOR+YEL "��\n");      
	line += sprintf( YEL "�ǩ���������������������������������������������������������������\n" NOR );
        line += sprintf( YEL "��"HIR" �� �� �� �� �� ��                                            "NOR+YEL"��\n" NOR );
        line += sprintf( YEL "�ǩ���������������������������������������������������������������\n" NOR );
        line += sprintf( YEL "��" HIY "�����ɡ�" NOR "%-12s" ,
                 my["club"] ? string_m(my["club"], 12):string_m("δ�������", 12) );
        line += sprintf( HIY "����ҵ��" NOR "%-13s" ,
                 my["newjob/estate"] ? string_m(my["newjob/estate"], 12):string_m("δ����", 12) );
        line += sprintf( HIY "��סլ��" NOR "%-13s" YEL "��\n" NOR ,
                 my["newjob/dwelling"] ? string_m(my["newjob/dwelling"], 12):string_m("¶�޽�ͷ", 12) );
        line += sprintf( YEL "��" HIY "��ְҵ��" NOR "%-12s" ,
                 my["newjob/jobtitle"] ? string_m(my["newjob/jobtitle"], 12):string_m("δ����", 12) );
        line += sprintf( HIY "���ȼ���" NOR "%-13s" ,
                 my["newjob/level"] ? string_m(my["newjob/level"], 12):string_m("δ����", 12) );
        line += sprintf( HIY "�����롿" NOR "%-13s" YEL "��\n"NOR ,
                 my["newjob/income"] ? string_m(chinese_number(my["newjob/income"]), 12):string_m("δ����", 12) );
	line+=sprintf( YEL "������������������������������������������������������������������\n" NOR );


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
        
        return tough_level_desc[lvl];
}
string tribar_graph(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*12/max)*2-1]
		+ ((eff > val) ? blank_string[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}
string tribar_graph2(int val, int eff, int max, string color)
{
	return color + bar_string[0..(val*12/max)*2-1]
		+ ((eff > val) ? blank_string2[(val*12/max)*2..(eff*12/max)*2-1] : "") + NOR;
}
string tribar_graph3(int a)
{
	return BLU + blank_string3[0..(23-a)] + NOR;
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
