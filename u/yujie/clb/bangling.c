//Cracked by yujie
// /d/huanghe/obj/bangling.c
// by 13/9/2001

#define BANGZHU   "/d/huanghe/npc/bangzhu"
#define DASHOU    "/d/huanghe/npc/dashou"

#include <ansi.h>
#include <localtime.h>

inherit ITEM;

#include "/d/REGIONS.h"
#include "/d/huanghe/doc/info_store.h"
#include "/d/huanghe/doc/bangskills.h"


void create()
{
        set_name("帮令", ({ "bang ling", "ling" }) );
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "块");
                set("long", "这是一块帮会中常用的帮令。\n");
                set("value", 0);
                set("material", "wood");
                set("no_drop", "这样东西不能离开你。\n");
                set("no_get", "这样东西不能离开那儿。\n");
        }
        setup();
}

void init()
{
        add_action("do_collect", "collect");
        add_action("do_sign", "sign");
        add_action("do_find", "find");
        add_action("do_bargain", "bargain");
        add_action("do_huan","huan");
        add_action("do_huan","change");
}

int do_find(string arg)
{
        object *obj, room;
        string file, region, fam, result;
        int i;
        mapping job;
        object me = this_player();

        if( (string)query("owner") != this_player()->query("id") ) {
               write("你连自己的帮令都管不好，还是离开帮会吧。\n");
               return 1;
        }

        if( !stringp(fam = this_player()->query_temp("bangs/fam")) ) {
               write("你没有加入帮会。\n");
               return 1;
        }

        if( arg == "score" ) {
                write("目前为止你一共积累了" + chinese_number((int)me->query("clbscore")) + "点功劳点。\n");
                return 1;
        }

        if( arg != "job" ) {
                write("你可以查询的有：job和score。\n");
                return 1;
        }

        if( !mapp(job = query("job")) ) {
                write("你现在没有被指派帮务。\n");
                return 1;
        }

        result = "你当前的帮务是";
        switch(job["type"]) {
        case "寻":
                result += "找" + job["name"]; 
                break;
        case "杀":
                result += "杀" + job["area"] + "的" + job["name"]; 
                break;
        case "摊费":
                result += "要" + job["name"] + "的摊费";
                break;
        case "截镖":
                result += "截" + job["name"] + "的镖";
                break;
        case "示威":
                result += "向" + job["name"] + "示威";
                break;
        case "送礼":
                result += "送礼给" + job["area"] + "的" + job["title"];
                break;
        case "护驾":
	        result += "护送帮主至" + job["dest"];
                break;
        case "买卖":
                result += "将" + job["name"] + "卖个好价钱";
                break;
        case "伙计":
                result += "在天宝阁做伙计";
                break;
	default:
                write("你现在没有被指派帮务。\n");
                return 1;
        }

        write(result + "。\n");
        return 1;     
}

int do_collect(string arg)
{
        object me = this_player();
        object victim, obj, obnpc,ft;
        int ap, dp, myexp, yourexp, bonus, record,level,i;
        string  bc_skills, *weapons, *bc_enskills ,weapon_skills,sp_skills;
        mapping job;
        int addscore;

        if( time() < (int)query("collect_time") + random(10) )
                return notify_fail("你刚向此人要过钱。\n");

        if( (int)me->query("jingli") < 50 || (int)me->query("jing") < 50 )
                return notify_fail("你太累了，先歇会儿。\n");

        if( (string)query("owner") != me->query("id") )
                return notify_fail("帮令岂能瞎用？\n");

        if( (string)query("fam") != me->query_temp("bangs/fam") )
                return notify_fail("你已经不是此帮的人了。\n");

        if( !mapp(job = query("job")) )
                return notify_fail("你现在没有帮务缠身。\n");

        if( job["type"] != "摊费" )
                return notify_fail("你当前的帮务不是收摊费。\n");

        if( base_name(environment(me)) != job["place"] )
                return notify_fail("你还没到" + job["name"] + "收什么摊费？\n");

        if( !arg )
                return notify_fail("你要向谁收括钱？\n");

        if( !(victim = present(arg, environment(me))) )
                return notify_fail("这儿没有这个人。\n");

        if( victim->name() != job["boss"] )
                return notify_fail("你找错人了。\n");

        if( !living(victim) )
                return notify_fail("你还是等此人醒来后再收括钱吧。\n");

        if( victim->is_busy() || victim->is_fighting() )
                return notify_fail("此人正忙着。\n");

        message_vision(HIR"\n$N向$n大声吆喝道：我是" + (string)query("fam") + "来收摊费的，识时务的赶快给钱！！！\n"NOR, me, victim);

        me->receive_damage("jingli", 20 + random(10));
        me->receive_damage("jing", 20 + random(10));

        set("collect_time", time());
        myexp = (int)me->query("combat_exp");
      
              
        if ((int)this_object()->query("job/is_kill")==1) 
        {
          if (ft=present("fighter",environment(victim)))
            if (ft->query("killob")==me)
            { write("先把眼前的打手干掉再说吧。\n");
             return 1;
            }     
     
          if (me->query("job/killer")=="me")
          {
                 
            message_vision("$N对$n说道：" + RANK_D->query_respect(me) + "果然英雄了得，这一点摊费是小的该付的。\n", victim, me);
            message_vision("$N接着说道：" + RANK_D->query_respect(me) + "请放心，我马上派人将钱送到贵帮！！！\n", victim);
    
            bonus = 60 + random(15) - me->query("combat_exp")/200000;
            addscore=query("score")/10000;
            if (addscore>30) addscore=30;
            bonus = bonus + addscore;
            
            record = bonus * 3 + random(bonus/2);
            me->add("combat_exp", record);
            log_file("test/BangJob", sprintf("%s于%s时因收摊费得%s经验点\n", me->query("name"), ctime(time()), chinese_number(record)));
            tell_object(me,HIW"你这次工作共得到"+chinese_number(bonus)+"点功劳点，" + chinese_number(record)+ "点经验值。\n"NOR);
            me->add("clbscore",bonus);
            delete("job");
            return 1;
          }
          message_vision("$N对$n说道：" + RANK_D->query_respect(me) + "靠别人自己并没有本事赢，小人不服，摊费是怎么也不会交的。\n",victim,me);
          return 1;
        }
             
        if ((random(me->query("combat_exp"))/1000)>10)
        {
           obnpc = new(DASHOU);
           obnpc->move(environment(me));
           set("job/is_kill",1);
           obnpc->set("combat_exp", myexp);
           level = ceil( pow( to_float(myexp) * 10.0, 0.333333) ) * 4 / 5;

           obnpc->set("max_qi",    level * 8 + 100);
           obnpc->set("max_jing",  level * 5 + 100);
           obnpc->set("qi",    level * 8 + 100);
           obnpc->set("jing",  level * 5 + 100);
           obnpc->set("max_neili", level * 6 + 200);
           obnpc->set("neili",     level * 6 + 200);
           obnpc->reincarnate();
           obnpc->clear_condition();
           

           obnpc->set_skill("dodge", level);
           obnpc->set_skill("force", level);
           obnpc->set_skill("parry", level);

           bc_skills = keys(unarmed_skills)[random(sizeof(keys(unarmed_skills)))];
           bc_enskills=unarmed_skills[bc_skills];
           sp_skills=bc_enskills[random(sizeof(bc_enskills))];
           obnpc->set_skill(bc_skills, level);
           obnpc->set_skill(sp_skills,level);
           obnpc->map_skill(bc_skills,sp_skills);
           obnpc->prepare_skill(bc_skills,sp_skills);
           obnpc->map_skill("parry", sp_skills);

        
           i = random(sizeof(info_weapon));
           obnpc->set_skill(info_weapon[i]["type"], level);
           weapon_skills=info_weapon[i]["skills"][random(sizeof(info_weapon[i]["skills"]))];
           obnpc->set_skill(weapon_skills,level);
           obnpc->map_skill(info_weapon[i]["type"],weapon_skills);

           level /= 3;
           obnpc->set_temp("apply/defense", level);
           obnpc->set_temp("apply/armor",   level);
           obnpc->set_temp("apply/damage",  level);
           obnpc->set_temp("apply/attack",  level);

           if( !random(2) ) {
                weapons = info_weapon[i]["weapons"];
                obnpc->carry_object(weapons[random(sizeof(weapons))])->wield();
           }
           
        message_vision("$N忽然从身后叫出一个强横的打手，冲$n阴笑道：想收保护费，得问问我们这位兄弟。\n", victim, me);
        message_vision(HIY"只见一个十分凶横的打手呼地一声窜到$N的面前大吼出手。\n"NOR, me);
        message_vision(HIY"$N仓促之间被攻了个措手不及，狼狈的招架着。\n"NOR, me);        
        obnpc->kill_ob(me);
        obnpc->set("killob",me);
        return 1;
  
        }
        
        ap = (int)query("combat_exp") + myexp * 10;

        yourexp = (int)victim->query("combat_exp");
        if( yourexp < 30000 ) yourexp = 30000;
        dp = yourexp * 30;

        
        
        if( random(ap + dp) < dp ) {
                message_vision("$N大怒道：什么" + (string)query("fam") + "，还不快滚！！！\n", victim);
                return 1;
        }
        
        message_vision("$N对$n说道：" + RANK_D->query_respect(me) + "辛苦了，这一点摊费是小的该付的。\n", victim, me);
        message_vision("$N接着说道：" + RANK_D->query_respect(me) + "请放心，我马上派人将钱送到贵帮！！！\n", victim);

        bonus = 40 - me->query("combat_exp")/100000;
        if (bonus<10)  bonus=10;
        addscore=query("score")/10000;
        if (addscore>30) addscore=30;
        bonus = bonus + addscore;
        record = bonus*2 + random(bonus);
        me->add("combat_exp", record);
        log_file("test/BangJob", sprintf("%s于%s时因收摊费得%s经验点\n", me->query("name"), ctime(time()), chinese_number(record)));

        tell_object(me,HIW"你这次工作共得到"+chinese_number(bonus)+"点功劳点，" + chinese_number(record)+ "点经验值。\n"NOR);
        me->add("clbscore",bonus);                  
        delete("job");
        return 1;
}

int do_sign(string arg)
{
        object obj, room;
        object me = this_player();
        int bonus, record;
        mapping job;
        int addscore;

        if( query("owner") != me->query("id") )
                return 0;

        if( (string)query("fam") != (string)me->query_temp("bangs/fam") )
                return 0;

        if( !arg || arg != "corpse" || !(obj = present(arg, environment(me))) )
                return notify_fail("你要在哪里做标记？\n");

        if( !mapp(job = query("job")) ) {
                tell_object(me, "你现在没有帮务。\n");
                return 1;
        }

        if( obj->query("my_killer") != me->query("id")
        ||  obj->query("signed")
        ||  (string)obj->query("victim_name") != job["name"] )
                return 0;

        if( !( room = find_object("/d/taishan/fengchan")) )
                room = load_object("/d/taishan/fengchan");

        if( me->query("id") == room->query("winner") ) {
                tell_object(me, "怕死，不中用的东西！\n");
                return 1;
        }

        obj->set("signed", 1);
        bonus = job["bonus"] + random(job["bonus"]);
        addscore=query("score")/10000;
        if (addscore>30) addscore=30;
        bonus = bonus + addscore;
        
        record = bonus*2 + random(bonus/2*3);
        me->add("combat_exp", record);
        log_file("test/BangJob", sprintf("%s于%s时杀%s得%s经验点\n", me->query("name"), ctime(time()), job["name"], chinese_number(record)));

        message_vision("$N在尸体旁写下“与" + (string)query("fam") + "为敌者杀！”几个大字。\n", me);
        tell_object(me,HIW"你这次工作共得到"+chinese_number(bonus)+"点功劳点，" + chinese_number(record)+ "点经验值。\n"NOR);
        me->add("clbscore",bonus);
        delete("job");
        return 1;
}

int do_bargain(string arg)
{
        object target, obj, me = this_player();
        mapping job;
        int bonus, exp,price,okprice;

        
        if( me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙着呢。\n");
                
        if (query("owner") != me->query("id"))
                return notify_fail("帮令岂能瞎用？\n");

        if( (string)query("fam") != me->query_temp("bangs/fam") )
                return notify_fail("你已经不是此帮的人了。\n");

        if( !mapp(job = query("job")) )
                return notify_fail("你现在没有帮务缠身。\n");
	
	if ( job["type"] != "买卖" )
		return notify_fail("你现在的帮务不是做买卖。\n");
		
        if( !arg )
                return notify_fail("你要和谁讨价还价？\n");

        if( !(target = present(arg, environment(me))) )
                return notify_fail("这儿没有这个人。\n");

        if( !living(target) )
                return notify_fail("他这个样子是没法子和你做买卖的。\n");

        if( userp(target) )
                return notify_fail("玩家不会出好价钱的。\n");

        if( target->query("race") && target->query("race") != "人类" )
                return notify_fail("他不是人类，看清楚一点！\n");

        if( target->is_busy() || target->is_fighting() )
                return notify_fail(target->name() + "正忙着。\n");

        if( (exp = (int)target->query("combat_exp")) < 20000 ) {
                message_vision("$N摆了摆手说道：我买不起，你卖给别人吧。\n", target);
                return 1;
        }

        if( !(obj = present(job["good"], me)) )
                return notify_fail("你把" + job["name"] + "都弄丢了。\n");

        if( time() < (int)target->query("trader/time") + 600 ) {
                message_vision("$N 摆了摆手说道：我刚买了一" + obj->query("unit") + obj->name() + "。\n", target);
                return 1;
        }
        
        if( explode(base_name(environment(target)), "/")[1] == "forest" )
        	return notify_fail("笨蛋，怎么能拿本帮的东西到自己的地盘上卖？\n");
        
        if( explode(base_name(environment(target)), "/")[1] == query("job/place") )
        	price=obj->query("highprice");
        else
        	price=obj->query("lowprice");
        
        if (me->query("jingli")<30)
        	return notify_fail("你先振作一下精神再和别人讨价还价把。\n");
        
        me->receive_damage("jingli",20);
                
        okprice=price/4+random(price);
        
        if (!stringp(query("job/bargainman")) || query("job/bargainman")!= target->query("name"))
        {      	message_vision("$N对$n说道：我这里有"+ obj->query("unit") + obj->name() + "不知道你能出个什么价。\n",me, target);
        	message_vision("$N仔细考究了一翻后，答道：这个我只能出"+chinese_number(okprice)+"两银子，中的话就成交(trade)吧。\n",target);
        }else
        {	message_vision("$N对$n说道：我这可是上好的货色呀，你这价钱是不是低了点呀。\n",me,target);
        	message_vision("$N不耐烦的说道：现在就"+chinese_number(okprice)+"两银子这个价，卖的话就成交(trade)，不卖拉倒。\n",target);
        }
        set("job/bargainman",target->query("name"));
        set("job/price",okprice);
        remove_action("do_trade","trade");
        add_action("do_trade","trade");
        me->start_busy(3);
        return 1;
}

int do_trade(string arg)
{
        object target, obj, me = this_player(),obgold;
        mapping job;
        int bonus,exp,okprice,numb;
        int addscore;

        if( me->is_busy() || me->is_fighting() )
                return notify_fail("你正忙着呢。\n");
                
        if (query("owner") != me->query("id"))
                return notify_fail("帮令岂能瞎用？\n");

        if( (string)query("fam") != me->query_temp("bangs/fam") )
                return notify_fail("你已经不是此帮的人了。\n");

        if( !mapp(job = query("job")) )
                return notify_fail("你现在没有帮务缠身。\n");

        if( !arg )
                return notify_fail("你要和谁成交？\n");

        if( !(target = present(arg, environment(me))) )
                return notify_fail("这儿没有这个人。\n");

        if( !living(target) )
                return notify_fail("他这个样子是没法子和你做买卖的。\n");

        if( userp(target) )
                return notify_fail("玩家不会出好价钱的。\n");

        if( target->is_busy() || target->is_fighting() )
                return notify_fail(target->name() + "正忙着。\n");

        if( (exp = (int)target->query("combat_exp")) < 20000 ) {
                message_vision("$N摆了摆手说道：我买不起，你卖给别人吧。\n", target);
                return 1;
        }

        if( !(obj = present(job["good"], me)) )
                return notify_fail("你把" + job["name"] + "都弄丢了。\n");

        if( time() < (int)target->query("trader/time") + 600 ) {
                message_vision("$N 摆了摆手说道：我刚买了一" + obj->query("unit") + obj->name() + "。\n", target);
                return 1;
        }
        
        if (query("job/bargainman") != target->query("name"))
                return notify_fail("你好象还没和他讲过价，怎么成交？\n");
        
        message_vision("$N爽快的说道：好吧，就这个价钱成交了。希望我们以后还有机会再做生意。\n",me);
        message_vision("接着$N把"+obj->query("unit") + obj->name() + "交给$n。\n", me, target);
        message_vision("$N点了点头，说道：下次贵帮来人时我再付款。\n", target);
        
        target->set("trader/time", time());
       
        bonus = 30+((int)query("job/price") - (int)obj->query("lowprice"))/((int)obj->query("lowprice")/20);
        addscore=query("score")/10000;
        if (addscore>30) addscore= 30;
        bonus = bonus + addscore;
        if (bonus<28)
        {	write("真笨！你这次买卖亏本了啦。\n");
        	destruct(obj);
        	delete("job");
        	remove_action("do_trade","trade");
        	return 1;
        }
        else
        {	write("你这次买卖赚到了。\n");
        	numb=((int)query("job/price")-(int)obj->query("lowprice"))/200;
        	if ( numb > 0)
        	{	write("你偷偷地想：赚了这么多，自己拿点总管也发现不了的。\n");
        		obgold=new("/clone/money/gold");
        		obgold->set_amount(numb);
        		obgold->move(me);
        		message_vision("$N嘿嘿奸笑着把"+chinese_number(numb)+"两金子塞进了自己的怀中。\n",me);
        	}
        }
        exp=bonus*2+random(bonus/2);
        me->add("combat_exp",exp );
        tell_object(me,HIW"你这次工作共得到"+chinese_number(bonus)+"点功劳点，" + chinese_number(exp)+ "点经验值。\n"NOR);
        
        log_file("test/BangJob", sprintf("%s于%s时因卖%s得%s经验点\n", me->query("name"), ctime(time()), obj->name(), chinese_number(exp)));
      
	me->add("clbscore",bonus);
        destruct(obj);
        delete("job");
        remove_action("do_trade","trade");
        return 1;
}

int do_huan(string arg)
{	int bef,aft,left;
	object me=this_player();

	if (query("owner") != me->query("id"))
                return notify_fail("帮令岂能瞎用？\n");

        if( (string)query("fam") != me->query_temp("bangs/fam") )
                return notify_fail("你已经不是此帮的人了。\n");
                
        if (!arg || sscanf(arg,"%d",bef)!= 1)
        	return notify_fail("正确指令格式：huan <用来兑换的功劳点数>\n");
        
        if (bef < 1)
        	return notify_fail("用来兑换的功劳点数必须大于零。\n");
        
        if ( me->query("clbscore")< bef)
        	return notify_fail("你拥有的功劳点数不够兑换。\n");
                
        me->add("clbscore",-bef);
        me->add("potential",bef);
        write("你将"+chinese_number(bef)+"点长乐帮功劳点兑换成潜能。\n");
        log_file("ConvertLog", sprintf("%s 于 %s 时将 %s 点功劳点兑换成潜能\n", me->query("name"), ctime(time()), chinese_number(bef)));
        write("小心转换的潜能超过上限必须尽快学完，否则退出游戏潜能会掉的。\n");
        return 1;
}
        

