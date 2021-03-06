// by momo 11/1 . 2001
// score.c

#include <ansi.h>
#include <combat.h>

inherit F_CLEAN_UP;
string bar_string = "■■■■■■■■■■■■";
string blank_string = "□□□□□□□□□□□□";
string blank_string3 = "□□□□□□□□□□□□";
string blank_string2 = "　　　　　　　　　　　　";
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
		if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else if (ob != me)
		return notify_fail("只有巫师能察看别人的状态。\n");
	my = ob->query_entire_dbase();
	jings = (my["eff_jing"]*12/my["max_jing"])*2;
	qis = (my["eff_qi"]*12/my["max_qi"])*2;
	if ( userp(ob) ) line = sprintf(HBBLU"　　　　　　　　　　"HIY"【神州】个人档案(%-4s中文)"HIG"　　　　　　　　　　\n\n"+NOR, string_m(my["language"], 4),);
	line += sprintf( BOLD "  %s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1) );
	ob->update_age();
	
        line += sprintf( YEL "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n" NOR );
        line += sprintf( YEL "┃"HIR" 【 基 本 属 性 】                                            "NOR+YEL"┃\n" NOR );
        line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━┫\n" NOR );
        line += sprintf( YEL "┃" HIY "【年龄】" NOR "%6.6s岁%-12.12s      " YEL "┃" NOR ,
 		chinese_number(ob->query("age")),
		ob->query("month")?"零" +chinese_number(ob->query("month")) + "个月":"");
		
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

      line += sprintf( HIW "【攻击力】" NOR "      %15s  " YEL "┃\n" NOR ,
		pula);

         line += sprintf( YEL "┃" HIY "【性别】" NOR "%-26.8s" YEL "┃" NOR ,
                    ob->query("gender"));
                                        
      line += sprintf( HIW "【躲闪力】" NOR "      %15s  " YEL "┃\n" NOR ,
                pulb);

      line += sprintf( YEL "┃" HIY "【生辰】" MAG "%-22.22s" NOR+YEL "    ┃" NOR ,
                CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60) );

       line += sprintf( HIW "【防御力】" NOR "      %15s  " YEL "┃\n" NOR ,
                pulc);
	line += sprintf( YEL "┃                          ┏━━━┻━━━━━━━━━━━━━┫\n" NOR,);      
      if( mapp(my["family"]) )
  {
	if( my["family"]["family_name"] )
	 line += sprintf( YEL "┃" HIW "【门派】" NOR "%-18.8s" YEL "┃" NOR,
				my["family"]["family_name"] );
        else  
         line += sprintf( YEL "┃" HIW "【门派】" NOR "普通百姓          " YEL "┃" NOR );
  }
  else  
         line += sprintf( YEL "┃" HIW "【门派】" NOR "普通百姓          " YEL "┃" NOR );

        line += sprintf( HIY "【膂力】" HIW "%3d|%3d    " HIY "【悟性】" HIW "%3d|%3d" NOR+YEL "┃\n" NOR , 
                ob->query_str(),
                ob->query("str"), 
		ob->query_int(),
		ob->query("int"));

      if( mapp(my["family"]) )
  {
	if( my["family"]["master_name"] )
	 line += sprintf( YEL "┃" HIW "【师承】" NOR "%-18.8s" YEL "┃" NOR,
				my["family"]["master_name"] );
        else
         line += sprintf( YEL "┃" HIW "【师承】" NOR "你还没有拜师      " YEL "┃" NOR );
  }
  else  
         line += sprintf( YEL "┃" HIW "【师承】" NOR "你还没有拜师      " YEL "┃" NOR );
        line += sprintf( HIY "【根骨】" HIW "%3d|%3d    " HIY "【身法】" HIW "%3d|%3d" NOR+YEL "┃\n" NOR , 		
		ob->query_con(),
                ob->query("con"), 
		ob->query_dex(),
		ob->query("dex"));
	if (ob->is_married())
	line += sprintf(YEL "┃" HIW "【%s】" NOR "%-18.8s" YEL "┗━━━━━━━━━━━━━━━━━┫\n" NOR , my["spouse"]["title"],my["spouse"]["name"] );
	else if( ob->query_temp("marriage") && (ob->query_temp("marriage/accept") || ob->query_temp("marriage/banquet")))
        line += sprintf(YEL "┃" HIW "【%s】" NOR "%-16.8s" YEL "┗━━━━━━━━━━━━━━━━━┫\n" NOR ,
			my["gender"]=="女性"?"未婚夫":"未婚妻",
                        my["gender"]=="女性"?ob->query_temp("marriage/accept")->query("name"):ob->query_temp("marriage/banquet")->query("name"));
	else line += sprintf( YEL "┃" HIW "【婚姻】" NOR "单身              " YEL "┗━━━━━━━━━━━━━━━━━┫\n" NOR );
	line += sprintf( YEL "┃" HIW "【结义】"NOR);
	if ( ob->is_jiebaied() )
	{
		ob->jiebai_check();
		cnt = ob->jiebai_cnt();
		if (cnt != 0)
		{
			for( i=0; i<cnt; i++)
			{
				j++;
				line += sprintf( "%-18s%s" ,ob->jiebai_list(i),(j != cnt)? ((j%3==0) ? YEL "┃\n┃　　　　" NOR:""):"" );
				}	
			if (j%3 == 0) line += sprintf( YEL "┃\n" NOR );	
			if (j%3 == 1) line += sprintf( YEL "%36s┃\n" NOR,"" );	
			if (j%3 == 2) line += sprintf( YEL "%18s┃\n" NOR,"" );	
                }else line += sprintf( "你没有结拜的玩家%38s"YEL"┃\n" NOR,"" );
	}else{
                line += sprintf( "未开放%48s"YEL"┃\n" NOR,"" );
	}
	if (ob->query("balance") <= 0)
		line += sprintf( YEL "┃" HIW "【钱庄积蓄】" HIY "没有积蓄                                          " NOR+YEL "┃\n" NOR );
	else
         {
         	line += sprintf ( YEL "┃"  HIW "【钱庄积蓄】" NOR );
         	line += sprintf ("%-50.50s",
         	money_str(ob->query("balance")));
         	line += sprintf ( NOR+YEL "┃\n" NOR );
         	}
	line += sprintf( YEL "┃                                                              ┃\n" NOR );
	line += sprintf( YEL "┃" HIG "【经验】" NOR "%-20d \t" YEL,ob->query("combat_exp"));
	line += sprintf( HIG " 【%s】" NOR "%-18d" YEL "     ┃\n" NOR ,
                 ob->query("shen")<0?"邪气":"正气",
	         ob->query("shen") );
	line += sprintf( YEL "┃                                                              ┃\n" NOR );
        if( my["max_jing"] >= my["eff_jing"])
		line += sprintf( YEL "┃" HIC" 精  "NOR"：%-24s ", tribar_graph(my["jing"], my["eff_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"])) + tribar_graph3(jings));
	else
		line += sprintf( YEL "┃" HIC" 精  "NOR"：%-24s " , tribar_graph2(my["jing"], my["max_jing"], my["max_jing"], status_color(my["jing"], my["max_jing"]))+ tribar_graph3(jings));

	if( my["max_jingli"] > 0 )
		line += sprintf( HIC "精力"NOR"：%-24s"+ NOR+YEL+"┃\n"NOR, tribar_graph(my["jingli"], my["max_jingli"], my["max_jingli"], status_color(my["jingli"], my["max_jingli"])));
	else
		line += sprintf( HIC "精力"NOR"：%-24s\n");

	if( my["max_qi"] >= my["eff_qi"])
		line += sprintf( YEL "┃" HIC" 气  "NOR"：%-24s ", tribar_graph(my["qi"], my["eff_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));
	else	
		line += sprintf( YEL "┃" HIC" 气  "NOR"：%-24s ", tribar_graph2(my["qi"], my["max_qi"], my["max_qi"], status_color(my["qi"], my["max_qi"])) + tribar_graph3(qis));

	if( my["max_neili"] > 0 )
		line += sprintf( HIC "内力"NOR"：%-24s"+ NOR+YEL+"┃\n"NOR, tribar_graph(my["neili"], my["max_neili"], my["max_neili"], status_color(my["neili"], my["max_neili"])));
	else
		line += sprintf( HIC "内力"NOR"：%-24s\n");

	if( ob->max_food_capacity() > 0 )
		line += sprintf( YEL "┃" HIC" 食物"NOR"：%-24s ", tribar_graph(my["food"], ob->max_food_capacity(), ob->max_food_capacity(), YEL));
	else
		line += sprintf( YEL "┃" HIC" 食物"NOR"：%-24s ");
	
	if( ob->max_water_capacity() > 0 )
		line += sprintf( HIC "饮水"NOR"：%-24s"+ NOR+YEL+"┃\n"NOR , tribar_graph(my["water"], ob->max_water_capacity(), ob->max_water_capacity(), CYN));
	else
		line += sprintf( HIC "饮水"NOR"：%-24s\n");
	if( my["max_potential"] > 0 )
		line += sprintf( YEL "┃" HIC" 潜能"NOR"：%-24s " , tribar_graph(my["potential"], my["max_potential"], my["max_potential"], GRN));
	else
		line += sprintf( YEL "┃" HIC" 潜能"NOR"：%-24s ");
         	line += sprintf( HIC "游戏时间"NOR": "HIM"%-20s"NOR+YEL"┃\n",FINGER_D->age_string(my["mud_age"]));
          
	line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );
        line += sprintf( YEL "┃"HIR" 【 死 亡 记 录 】                                            "NOR+YEL"┃\n" NOR );
        line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );        

	if (my["MKS"] + my["PKS"])
	{        
		line += sprintf( YEL "┃" HIB "【杀人】" NOR "%12.12s" NOR "位        ", 
			chinese_number(my["MKS"] + my["PKS"]));
		line += my["PKS"]?sprintf( HIB "【杀死玩家】" NOR "%12.12s位      " YEL "┃\n" NOR ,
	                chinese_number(my["PKS"])): HIB "【杀死玩家】" NOR "          零位      " YEL "┃\n" NOR ;
	}else 
 		line += ( YEL "┃" HIB "【杀人】" NOR "          零位        " HIB "【杀死玩家】" NOR "          零位      "YEL "┃\n" NOR );
	//line += sprintf(YEL "┃" CYN " 你从未杀过其他玩家。                                         " NOR+YEL "┃\n");
	if (my["death_count"] > 0)
	line += sprintf( YEL "┃" HIB "【死亡】" NOR "%12.12s次        " HIB "【有效死亡】" NOR "%12.12s次      " YEL "┃\n" NOR ,
	        chinese_number(my["death_count"]), chinese_number(my["death_times"]));
	else
        line += ( YEL "┃" HIB "【死亡】" NOR "          零次        " HIB "【有效死亡】" NOR "          零次      "YEL "┃\n" NOR );
	if (my["last_pk"])
	line += sprintf(YEL "┃" HIR " 你最后一次是对 "HIR"%-20s"HIR" 痛下杀手。               " NOR+YEL "┃\n",my["last_pk"]);
	if (my["last_death"])
	line += sprintf(YEL "┃" HIR " 你最后一次是被 "HIR"%-20s"HIR" 杀死。                   " NOR+YEL "┃\n",my["last_death"]);
	//line += sprintf(YEL "┃" CYN " 你从未被其他玩家直接杀过。                                   " NOR+YEL "┃\n");      
	line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );
        line += sprintf( YEL "┃"HIR" 【 其 他 档 案 】                                            "NOR+YEL"┃\n" NOR );
        line += sprintf( YEL "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n" NOR );
        line += sprintf( YEL "┃" HIY "【帮派】" NOR "%-12s" ,
                 my["club"] ? string_m(my["club"], 12):string_m("未加入帮派", 12) );
        line += sprintf( HIY "【产业】" NOR "%-13s" ,
                 my["newjob/estate"] ? string_m(my["newjob/estate"], 12):string_m("未开放", 12) );
        line += sprintf( HIY "【住宅】" NOR "%-13s" YEL "┃\n" NOR ,
                 my["newjob/dwelling"] ? string_m(my["newjob/dwelling"], 12):string_m("露宿街头", 12) );
        line += sprintf( YEL "┃" HIY "【职业】" NOR "%-12s" ,
                 my["newjob/jobtitle"] ? string_m(my["newjob/jobtitle"], 12):string_m("未开放", 12) );
        line += sprintf( HIY "【等级】" NOR "%-13s" ,
                 my["newjob/level"] ? string_m(my["newjob/level"], 12):string_m("未开放", 12) );
        line += sprintf( HIY "【收入】" NOR "%-13s" YEL "┃\n"NOR ,
                 my["newjob/income"] ? string_m(chinese_number(my["newjob/income"]), 12):string_m("未开放", 12) );
	line+=sprintf( YEL "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n" NOR );


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
                output = chinese_number(amount / 10000) + "两黄金";
                amount %= 10000;
        }
        else
                output = "";
        if (amount / 100) {
                output = output + chinese_number(amount / 100) + "两白银";
                amount %= 100;
        }
        if (amount)
                return output + chinese_number(amount) + "文铜板";
        return output;
}

string tough_level(int power)
{

	int lvl, rawlvl;
        string *tough_level_desc = ({
BLU "不堪一击" NOR,BLU "毫不足虑" NOR,BLU "不足挂齿" NOR,BLU "初学乍练" NOR,BLU "勉勉强强" NOR,
BLU "初窥门径" NOR,BLU "初出茅庐" NOR,BLU "略知一二" NOR,BLU "普普通通" NOR,BLU "平平淡淡" NOR,
GRN "平淡无奇" NOR,GRN "粗通皮毛" NOR,GRN "半生不熟" NOR,GRN "马马虎虎" NOR,GRN "略有小成" NOR,
GRN "已有小成" NOR,GRN "鹤立鸡群" NOR,GRN "驾轻就熟" NOR,GRN "青出于蓝" NOR,GRN "融会贯通" NOR,
CYN "心领神会" NOR,CYN "炉火纯青" NOR,CYN "了然于胸" NOR,CYN "略有大成" NOR,CYN "已有大成" NOR,
CYN "豁然贯通" NOR,CYN "出类拔萃" NOR,CYN "无可匹敌" NOR,CYN "技冠群雄" NOR,CYN "神乎其技" NOR,
HIB "出神入化" NOR,HIB "非同凡响" NOR,HIB "傲视群雄" NOR,HIB "登峰造极" NOR,HIB "无与伦比" NOR,
HIB "所向披靡" NOR,HIB "一代宗师" NOR,HIB "精深奥妙" NOR,HIB "神功盖世" NOR,HIB "举世无双" NOR,
MAG "惊世骇俗" NOR,MAG "撼天动地" NOR,MAG "震古铄今" NOR,MAG "超凡入圣" NOR,MAG "威镇寰宇" NOR,
MAG "空前绝后" NOR,MAG "天人合一" NOR,MAG "深藏不露" NOR,MAG "深不可测" NOR,WHT "返璞归真" NOR

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
指令格式 : score
           score <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的基本资料。
基本资料的设定请参阅 'help setup'。

see also : hp
HELP
    );
    return 1;
}
