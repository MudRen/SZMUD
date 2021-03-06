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
		if (!ob) return notify_fail("你要察看谁的状态？\n");
	} else if (ob != me)
		return notify_fail("只有巫师能察看别人的状态。\n");
	ob->update_age();
	my = ob->query_entire_dbase();
	col = ob->query("shen") == 0 ? HIG : (ob->query("shen")<0 ? HIB : HIR);
	my_shen = ob->query("shen") == 0 ? "未做江湖事" : ""+ob->query("shen")+"";
	my_exp = ob->query("combat_exp") > 0 ? ""+ob->query("combat_exp")+"" : "未入江湖";
	b_day = CHINESE_D->chinese_date(((int)ob->query("birthday") - 14*365*24*60) * 60);
	c_age = chinese_number(ob->query("age")) + "岁" + (ob->query("month")?((ob->query("month")<10)?"零":"") +chinese_number(ob->query("month")) + "个月":"");
	m_name = (!mapp(my["family"]))?"未拜师学艺":((!(my["family"]["master_name"]))?"未曾拜师学艺":my["family"]["master_name"]);
	m_gxd = (!mapp(my["menpai"]))?"无贡献":((!mapp(my["family"]) || !(my["family"]["master_name"]))?"你未拜师":string_m(""+my["menpai"]["gxd"]+"", 10)+"点");
	title = (!mapp(my["family"]))?"普通百姓":((!(my["family"]["family_name"]))?"普通百姓":my["family"]["family_name"]);
	qzjx = ((ob->query("balance") <= 0) ? "没有积蓄":MONEY_D->money_str(ob->query("balance")));
	if (ob->is_married()){
		marry_t = my["spouse"]["title"];
		marry_n = my["spouse"]["name"];
	}else if( ob->query_temp("marriage") && (ob->query_temp("marriage/accept") || ob->query_temp("marriage/banquet"))){
		if (my["gender"] == ob->query_temp("marriage/accept")->query("gender")){
			marry_t = "同性恋";
			if (ob->query_temp("marriage/accept"))
				marry_n = ob->query_temp("marriage/accept")->query("name");
			else marry_n = ob->query_temp("marriage/banquet")->query("name");
		}else{
			marry_t = (my["gender"] == "女性") ? "未婚夫":"未婚妻";
			marry_n = (my["gender"] == "女性") ? ob->query_temp("marriage/accept")->query("name"):ob->query_temp("marriage/banquet")->query("name");
		}
	}else{
		marry_t = "婚  姻";
		marry_n = "单身";
	}
	if( my["qi"]*100 / my["max_qi"]>=80 ) stzt = HIG + string_m("健康", 6);
        else if( my["qi"]*100 / my["max_qi"]>=60 ) stzt = HIR + string_m("轻伤", 6);
        else if( my["qi"]*100 / my["max_qi"]>=40 ) stzt = HIR + string_m("内伤", 6);
        else stzt = RED + string_m("重伤", 6);
	if( my["jingli"]*100 / my["max_jingli"]>=80 ) jszt = HIG + string_m("饱满", 6);
        else if( my["jingli"]*100 / my["max_jingli"]>=60 ) jszt = HIR + string_m("疲乏", 6);
        else if( my["jingli"]*100 / my["max_jingli"]>=40 ) jszt = HIR + string_m("疲倦", 6);
        else jszt = HIB + string_m("很累", 6);
	if ( userp(ob) ) line = sprintf(HBBLU+HIG+"※※※※※※※※※※"HIY"【神州】个人档案(%-4s中文)"HIG"※※※※※※※※※※\n\n"+NOR, string_m(ob->query("language"), 4),);
	else line = sprintf(HBBLU+HIG+"※※※※※※※※※※※※"HIY" 【神州】NPC 档案 "HIG"※※※※※※※※※※※※\n\n"+NOR);

	line += sprintf( BOLD "%s" NOR "%s\n", RANK_D->query_rank(ob), ob->short(1) );
        line += sprintf(BLU"─────────────────────────────────\n"NOR);
        line += sprintf( HIC "膂力：" NOR+CYN "[" HIW "%3d" + NOR+CYN +"/" WHT "%3d" NOR+CYN "]　" HIC "悟性：" NOR+CYN "[" HIW  "%3d" + NOR+CYN +"/" WHT "%3d" NOR+CYN "]　" HIC "根骨：" NOR+CYN "[" HIW  "%3d" + NOR+CYN +"/" WHT "%3d" NOR+CYN "]　" HIC "身法：" NOR+CYN "[" HIW  "%3d" + NOR+CYN +"/" WHT "%3d" NOR+CYN "]\n\n" NOR , 
                ob->query_str(), ob->query("str"), ob->query_int(), ob->query("int"), ob->query_con(), ob->query("con"), ob->query_dex(), ob->query("dex"));
        line += sprintf("年龄：" NOR+CYN "[" HIG "%22s" NOR+CYN "]　" NOR, string_m(c_age, 22));
	line += sprintf("生辰：" NOR+CYN "[" MAG "%26s" CYN "]\n" NOR, string_m(b_day, 26));		
	line += sprintf("性别：" NOR+CYN "[" HIG "%6s" NOR+CYN "]　" NOR, string_m(ob->query("gender"), 6));
	line += sprintf("身体：" NOR+CYN "[%6s" NOR+CYN "]　" NOR, stzt);
	line += sprintf("精神：" NOR+CYN "[%6s" NOR+CYN "]　" NOR, jszt);
	line += sprintf("%6s：" NOR+CYN "[" HIG "%8s" NOR+CYN "]\n" NOR, marry_t, string_m(marry_n, 8) );
	line += sprintf("钱庄积蓄：" NOR+CYN "[" HIY "%54s" NOR+CYN "]\n" NOR, string_m(qzjx, 54));
	line += sprintf("江湖结义：" NOR+CYN "[" HIG );
	if ( ob->is_jiebaied() )
	{
		ob->jiebai_check();
		cnt = ob->jiebai_cnt();
		if (cnt != 0)
		{
			for( i=0; i<cnt; i++)
			{
				j++;
				line += sprintf( "%18s%s", string_m(ob->jiebai_list(i), 18),(j != cnt)? ((j%3==0) ?NOR+CYN "]\n　　　　　[" HIG:""):"" );
				}	
			if (j%3 == 0) line += sprintf( NOR+CYN "]\n\n" NOR );	
			if (j%3 == 1) line += sprintf( "%36s" NOR+CYN "]\n\n" NOR, "" );	
			if (j%3 == 2) line += sprintf( "%18s" NOR+CYN "]\n\n" NOR, "" );	
		}else line += sprintf( "%54s" NOR+CYN "]\n\n" NOR, string_m("你目前没有结拜的玩家", 54) );
	}else line += sprintf( "%54s" NOR+CYN "]\n\n" NOR, string_m("你目前没有结拜的玩家", 54) );

	line += sprintf( HIY "门派：" NOR+CYN "[" HIG "%12s" NOR+CYN "]　 "NOR, string_m(title, 12));
	line += sprintf( HIY "师承：" NOR+CYN "[" HIG "%12s" NOR+CYN "]　 "NOR, string_m(m_name, 12));
	line += sprintf( HIY "贡献：" NOR+CYN "[" HIG "%12s" NOR+CYN "]\n"NOR, string_m(m_gxd, 12));

	line += sprintf( HIC "经验：" NOR+CYN "[" HIG "%12s" NOR+CYN "]　 "HIC "%6s" NOR+CYN "[" + col + "%12s" NOR+CYN "]　 ", string_m(my_exp, 12), ob->query("shen") == 0 ? "名声：" : (ob->query("shen")<0 ? BLU"邪气："NOR : HIR"正气："NOR), string_m(my_shen, 12));
       	line += sprintf( HIC "在线: "NOR+CYN "[" MAG "%12s" NOR+CYN "]\n"NOR,userp(ob) ? string_m(FINGER_D->age_string(my["mud_age"]), 12):string_m("NPC无此项", 12));

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

	line += sprintf( HIW "攻击：" NOR+CYN "[%-12s" NOR+CYN "]　 "HIW "躲闪：" NOR+CYN "[%-12s" NOR+CYN "]　 "HIW "防御：" NOR+CYN "[%-12s" NOR+CYN "]\n\n"NOR, string_m(pula, 12), string_m(pulb, 12), string_m(pulc, 12));
         
	line += sprintf( HIB "杀人：" NOR+CYN "[" RED "%20s位" NOR+CYN "]　" HIB "杀死玩家：" NOR+CYN "[" HIR "%20s位" NOR+CYN "]\n" NOR,
		chinese_number(my["MKS"] + my["PKS"]), chinese_number(my["PKS"]));
	line += sprintf( HIB "死亡：" NOR+CYN "[" RED "%20s位" NOR+CYN "]　" HIB "有效死亡：" NOR+CYN "[" HIR "%20s次" NOR+CYN "]\n" NOR,
	        chinese_number(my["death_count"]), chinese_number(my["death_times"]));
	if (my["last_pk"] && my["last_death"])
		line += sprintf(HIR "你最后一次是对 "HIR"%20s"HIR" 痛下杀手。\n你最后一次是被 "HIR"%20s"HIR" 杀死。\n\n", string_m(my["last_pk"], 20), string_m(my["last_death"], 20));
	else if (!my["last_pk"] && my["last_death"])
		line += sprintf(HIR "你未对玩家痛下杀手，你最后一次是被 "HIR"%20s"HIR" 杀死。\n\n", string_m(my["last_death"], 20));
	else if (my["last_pk"] && !my["last_death"])
		line += sprintf(HIR "你最后一次是对 "HIR"%20s"HIR" 痛下杀手，你从未被玩家杀死过。\n\n", string_m(my["last_pk"], 20));
	else line += "\n";
        line += sprintf( HIY "帮派：" NOR+CYN "[" HIG "%12s" NOR+CYN "]　 " ,
                 ob->query("newjob/country") ? string_m(ob->query("newjob/country"), 12):string_m("未开放", 12) );
        line += sprintf( HIY "产业：" NOR+CYN "[" HIG "%12s" NOR+CYN "]　 " ,
                 ob->query("newjob/estate") ? string_m(ob->query("newjob/estate"), 12):string_m("未开放", 12) );
        line += sprintf( HIY "住宅：" NOR+CYN "[" HIG "%12s" NOR+CYN "]\n" NOR ,
                 ob->query("newjob/dwelling") ? string_m(ob->query("newjob/dwelling"), 12):string_m("露宿街头", 12) );
        line += sprintf( HIY "职业：" NOR+CYN "[" HIG "%12s" NOR+CYN "]　 " ,
                 ob->query("newjob/jobtitle") ? string_m(ob->query("newjob/jobtitle"), 12):string_m("未开放", 12) );
        line += sprintf( HIY "等级：" NOR+CYN "[" HIG "%12s" NOR+CYN "]　 " ,
                 ob->query("newjob/level") ? string_m(ob->query("newjob/level"), 12):string_m("未开放", 12) );
        line += sprintf( HIY "收入：" NOR+CYN "[" HIG "%12s" NOR+CYN "]\n" NOR,
                 ob->query("newjob/income") ? string_m(chinese_number(ob->query("newjob/income")), 12):string_m("未开放", 12) );
	write(line);
	return 1;
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
	else return "未知数据";
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
指令格式 : score
           score <对象名称>                   (巫师专用)

这个指令可以显示你(你)或指定对象(含怪物)的基本资料。
基本资料的设定请参阅 'help setup'。

see also : hp
HELP
    );
    return 1;
}
