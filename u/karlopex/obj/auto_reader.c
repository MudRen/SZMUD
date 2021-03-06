//自动读票机。
//written at 14/05/2002 by Karlopex@sz

#include <localtime.h>
#include <ansi.h> 
inherit ITEM;
inherit F_SAVE;

string *opt1 = ({ 
"25岁以下组",
"30岁以下组",
"35岁以下组",
"40岁以下组",
"45岁以下组",
"55岁以下组",
"65岁以下组",
"99岁以下组",
"五绝得主",
"天下第一门派",
});
mapping menpai = ([
	"hs":"华山派",
	"xx":"星宿派",
	"wd":"武当派",
	"dl":"大理段家",
	"gb":"丐帮",
	"xs":"雪山派",
	"th":"桃花岛",
	"gm":"古墓派",
	"sl":"少林派",
	"qz":"全真教",
	"em":"峨嵋派",
	"bt":"白驼山",
	"kl":"昆仑派",
/*	"mj":"明教",
	"xy":"逍遥派",
	"ry":"日月神教",
	"ts":"天山派",
	"lj":"灵鹫宫",
	"mr":"姑苏慕容",*/
]);
 
string query_save_file()
{
	return "/data/npc/xuanpiao";
}
int check_time(object piao);
string check_piao(object piao);

void create() 
{ 
	set_name(WHT"选票自动读票机"NOR, ({"auto reader" ,"reader"})); 
	set("title", HIG"神州比武大会"NOR); 
	set_weight(100000000);
	set_max_encumbrance(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "台");
		set("long","这是一台神州比武协会出品的"WHT"选票自动读票机"NOR"。\n如果想知道如何使用，请用"HIG"zhinan"NOR"指令。\n"); 
		set("value", 1000000);
		set("no_get",1);
		set("piao",0);
		set("shou",0);
		set("no_clean_up", 1);
	}
    	if ( restore() ) restore_object("/data/npc/xuanpiao");  
	setup();
} 

void init() 
{ 
        object me = this_player();
	if ( wizhood(me) == "(admin)" || wizhood(me) == "(arch)" || getuid(me) == "lnere"){
		add_action("do_set_time", "set_time");
		add_action("do_set_name", "set_name");
		add_action("do_check", "check");
	}
	add_action("do_qupiao", "na"); 
	add_action("do_qupiao", "qu"); 
	add_action("do_yanpiao", "yan"); 
	add_action("do_yanpiao", "dui");
	add_action("do_zhinan", "zhinan");
}
int do_set_time(string arg)
{
        object me = this_player();
        int year, mon, day, hour, min;

        if ( !arg || arg == "" ){
        	if ( query("settime") == "ok" )
			return notify_fail("你设置的是"+query("year")+"年"+query("mon")+"月"+query("day")+"日"+query("hour")+"点"+query("min")+"分。\n");
		else return notify_fail("请按<set_time 年,月,日,时,分>正确输入。\n");
	}

        if ( sscanf(arg , "%d,%d,%d,%d,%d" , year, mon, day, hour, min) != 5)
		return notify_fail("请按<set_time 年,月,日,时,分>正确输入。\n");

	if ( year < 2000 )
		return notify_fail("年份不对，请输入2000以上的数字。\n");

	if ( mon > 12 )
		return notify_fail("月份不对，请输入12以下的数字。\n");

	if ( ( mon <= 7 && mon%2 == 1 ) || ( mon >= 8  && mon%2 != 1 ) )
		if ( day > 31 )	return notify_fail("日期不对，"+chinese_number(mon)+"月只有31天。\n");
	else if ( mon == 2 ){
 		if ( year%4 != 0 && day > 28 )
			return notify_fail("日期不对，今年的"+chinese_number(mon)+"月只有28天。\n");
		else if ( year%4 == 0 && day > 29 )
			return notify_fail("日期不对，今年的"+chinese_number(mon)+"月只有29天。\n");
	}else if ( day > 30 ) return notify_fail("日期不对，"+chinese_number(mon)+"月只有30天。\n");
	
	if ( hour == 24 ) hour = 0;

	if ( hour > 23 ) return notify_fail("小时不对，一天只有24小时。\n");
	
	if ( min == 60 ) min = 0;

	if ( min > 59 ) return notify_fail("分钟不对，一小时只有60分钟。\n");	

	set("yeer" , year);
	set("mon" , mon);
	set("day" , day);
	set("hour" , hour);
	set("min" , min);
	set("settime" , "ok");	
	tell_object(me,"你的截止时间设置完毕，你设置的是"+year+"年"+mon+"月"+day+"日"+hour+"点"+min+"分。\n");
	save();
	return 1;
}

int do_set_name(string arg)
{
        object ob, me = this_player();
        string name, menu, menus, names = "";
        int i, j;
	string *mpx, mpname;
	mpx = keys(menpai);
	menus = "		25岁以下组\n";
	menus += "		30岁以下组\n";
	menus += "		35岁以下组\n";
	menus += "		40岁以下组\n";
	menus += "		45岁以下组\n";
	menus += "		55岁以下组\n";
	menus += "		65岁以下组\n";
	menus += "		99岁以下组\n";
	menus += "		五绝得主\n";
	menus += "		天下第一门派\n";
	menus += "其中门的代码有：\nhs ： 华山派    xx ： 星宿派    wd ： 武当派    kl ： 昆仑派\nxs ： 雪山派    th ： 桃花岛    gm ： 古墓派    sl ： 少林派\nqz ： 全真教    em ： 峨嵋派    bt ： 白驼山    gb ： 丐帮\ndl ： 大理段家\n";
        if ( !arg || arg == "" ){
        	if ( query("setname") == "ok" )
			return notify_fail("你已经把比武大会的名次设置完了。\n");
		else return notify_fail("请按<set 项目 名字>的格式正确输入。\n项目和门派代码如下：\n"+menus);
	}

	if ( arg == "set ok" ){
		set( "setname" , "ok" );
		tell_object(me,"你所有的比武结果数据输入完毕。\n");
		save();
		return 1;
	}

        if ( sscanf(arg , "%s %s" , menu, name) != 2)
		return notify_fail("请按<set_name 项目 名字>的格式正确输入。\n");

	if ( name == "none" ){
		set(menu,"此项未选");
		tell_object(me,"你设置的是"+menu+"项目，没有得主。\n");
		return 1;
	}
	
	if ( menu == "五绝得主" ){
		i = sizeof(explode(name, "\," ));
		if (i != 5)
		{ 
			write("你写的人数不是五个人，重新输入五绝得主。\n");				
	                return 1;
		}
		for(j=0;j<i;j++)
		{
			if (!objectp(ob = find_player(explode(name, "\," )[j])))
			{
				ob = new(USER_OB);
			        ob->set("id", explode(name, "\," )[j]);   
				if( !ob->restore() ) {
			        	write(HIR+ explode(name, "\," )[j] + "还未注册！"NOR"请重新输入五绝得主。\n");
					destruct(ob);
			                return 1;
				}
			}
			names += ob->name()+"("+explode(name, "\," )[j]+")，";	
		}
		names = names[0..<3];
		set(menu,explode(names, "\，" ));
		tell_object(me,"你设置的是"+menu+"项目，得主是"+names+"。\n");
		save();
		return 1;
	}else if ( menu == "天下第一门派" ){
		for (int k=0; k<sizeof(mpx); k++) {
			if (name == mpx[k] || name == menpai[mpx[k]])
			{
				if (name == mpx[k]) name = menpai[mpx[k]];
				write("你输入的"+menu+"得主是"+name+"。\n"NOR);
				save();
				return 1;
			}
		}
		write(HIR + name + "不是有效门派名或代码！请重新输入天下第一门派。\n"NOR);
		return 1;
	}	
	if (!objectp(ob = find_player(name)))
	{
		ob = new(USER_OB);
	        ob->set("id", name);   
		if( !ob->restore() ) {
	        	write(HIR+ name + "还未注册！"NOR"请重新输入"+opt1[i]+"的得胜者。\n");
			destruct(ob);
	                return 1;
		}
	}

	name = ob->name()+"("+name+")";
	set( menu , name);
	tell_object(me,"你设置的是"+menu+"项目，得主是"+name+"。\n");
	save();
	return 1;
}

int do_check()
{

	string zt = "本机正在开放中。\n";
	if ( query("piao") ) zt += "本机目前发放"+chinese_number(query("piao"))+"张第一届【神州】比武大会的选票。\n";
	if ( query("shou") ) zt += "本机目前收回"+chinese_number(query("piao"))+"张第一届【神州】比武大会的选票。\n";
	if ( query("busy") == "start" ) zt += "本机目前正在兑奖中。\n";
	write(HIG+zt+NOR);
	return 1;
}

int do_qupiao(string arg)
{
	object newpiao, me = this_player();

	if ( !arg || arg == "" ) return notify_fail("你要拿什么？\n");

	if ( arg != "xuanpiao" && arg != "piao")  return notify_fail("你要拿东西这里没有。\n");
	
	if( present(arg, me) || present(me->query("id")+"'s piao", me) )
		return notify_fail("选票就在你的身上。\n");
	
	newpiao = new(__DIR__"piao");
	newpiao->move(me);
	add("piao" , 1);
	message_vision(HIG"$N从$n"HIG"里拿出了一张比武大会的选票。\n"NOR, me, this_object());	
	save();
	return 1;
}

int do_yanpiao(string arg)
{
	object piao, me = this_player();

	if ( !arg || arg == "" ) return notify_fail("你要验什么？\n");
	if ( query("busy") == "start" ) return notify_fail("你要验什么？\n");
	if ( arg != "xuanpiao" && arg != "piao" && arg != me->query("id")+"'s piao" )
		return notify_fail("你的这个东西这里验不了。\n");
	
	if ( arg != me->query("id")+"'s piao" ) arg = me->query("id")+"'s piao";
	
	if ( !objectp( piao = present( arg , me ) ) )
		return notify_fail("你身上没有这样东西。\n");

	if ( !check_time( piao ) )
		return notify_fail("你填的太晚，此票已经作废。\n");

	message_vision(HIG"$N把填好的比武大会的选票放进了$n"HIG"里，开始兑奖。\n"NOR, me, this_object());
	piao->move(this_object());
	check_piao( piao );
	set("busy","stop");
	add("shou",1);
	return 1;		
}
int check_time(object piao)
{
	mixed *local;
	int year, mon, day, hour, min, time2;
	local = localtime(piao->query("done_time"));
       	if ( query("settime") != "ok" )
       		return piao->query("done_time") < time();
	year = query("year");
	mon = query("mon");
	day = query("day");
	hour = query("hour");
	min = query("min");
	if ( local[LT_YEAR] <= year ) return 1;
	if ( local[LT_MON] <= mon ) return 1;
	if ( local[LT_MDAY] <= day ) return 1;
	if ( local[LT_HOUR] < hour ) return 1;
	if ( local[LT_MIN] < min ) return 1;	
}
void check_piao(object piao)
{
	int i, j, cnt, count;
	string *name;
	name = piao->query("五绝得主");
	set("busy","start");
	for(i=0;i<sizeof(opt1);i++){
		if ( opt1[i] == "五绝得主" ){
			for(j=0;j<sizeof(name);j++){
				if (member_array(name[j], query(opt1[i])) != -1)
					cnt++;
			}
		}else if (piao->query(opt1[i]) == query(opt1[i]))
			count++;
	}
	if ( cnt == 5 ) count++;
	if ( count > 0){
		write("你共猜中"+chinese_number(count)+"个项目，其中五绝猜中"+chinese_number(cnt)+"个。\n");
		if ( count == 10 )
		write("恭喜，恭喜，你中奖了，你得到了50点贡献度的奖励。\n");
		this_player()->add("shenzhou/pts",50);
	}else write("很遗憾，你未中奖。\n");
}

int do_zhinan()
{
        object me = this_player();
        string str = "			本机功能如下：\n";
	if ( wizhood(me) == "(admin)" || wizhood(me) == "(arch)" || getuid(me) == "lnere"){
		str += "	一、<set_time 年,月,日,时,分>设置被检票的最后时间。\n";
		str += "	二、<set_name 项目, 名字>设置最后的比武结果。\n";
		str += "	三、<check>检查本机状态。\n";
		str += "	四、<[qu | na] piao>取票。\n";
		str += "	五、<[yan | dui] piao>验票，以及得出结果。\n";
	}else{
		str += "	一、<[qu | na] piao>取票。\n";
		str += "	二、<[yan | dui] piao>验票，以及得出结果。\n";
	}
	write (HIG+str+NOR);
	return 1;
}
		
	
	
	
	
		