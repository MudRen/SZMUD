// belong to jiuer @SZ


#include <mudlib.h>
#include <ansi.h>
#include <room.h>
#include <armor.h>
#include <command.h>
#include <net/dns.h>

inherit CLOTH;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;

string inputstr,verb;

void create()
{
  seteuid(getuid());

set("long",@LONG

    这是一件奇怪的物品。

    键入<help myst>以获得更多的资讯。

LONG
);

  set("unit","件");
  set("no_drop", 1);
  set("no_get", 1);

  set("material", "cloth");
  set("armor_prop/armor", 100);
  set_weight(10);
  setup();
}

void init()
{
  object me;                   
  seteuid(geteuid());

  me = this_player();
  if (me && present(this_object(), me))
    set_name (me->name(1)+ "的神秘物品", ({ "myst" }));
  else
    set_name ("神秘物品", ({ "myst" }));

  if (me && present(this_object(), me)) {
  add_action("help","help");
  add_action("full","full");
  add_action("remov","xie");
  add_action("wave","yao");
  add_action("steal","tou");
  add_action ("whereis", "whereis");
  add_action ("pk_mob", "pk");
  add_action ("do_give", "give");
  add_action ("do_wakeup", "wakeup");
  add_action ("force_quit", "fquit");
  add_action ("do_say", "ss");
  add_action ("do_who", "userlist");
  add_action ("do_look", "lookhere");
  add_action ("do_hun", "hun");
  add_action ("do_tear","tear");
  add_action ("do_back", "back");
  add_action("do_pace","pace");
  add_action("do_heal","heal");
	}
}

int help(string str)
{

  if (str!="myst") return 0;

write(@Help

    你可以使用以下的几个命令:

       % localcmd, stat, call, data, score, skills, 等等
         请用 help wizcmds 取得进一步资料

       yao <number> <type>		    <取出哪种钱币的多少数目>
       xie <eqs> from <object>		<让某一 object 解除装备>
       tou <object> from <object>	<从某玩家或object身上拿某样东东>
       pk <生物1> with <生物2>		<让生物1 与生物2 互 k>
       whereis <玩家>			    <显示一玩家的所在地>
       full <玩家>              	<全医, 玩家若无输入则内定为自己>
       wakeup <玩家>			    <把昏迷不醒的玩家叫醒>
       userlist <-i|-l|-w>		    <who的功能>
       lookhere				        <look本房间>
	   hun <生物>                   <昏迷玩家>
	   back <生物>                  <send player back to wumiao>
	   tear <myst>                  <tear myst>
Help

);

  return 1;
}

int do_heal(string arg) {
      object obj;
      
      if (!arg) obj=this_player();
         else if (!objectp(obj = present(arg, environment(this_player()))))
                     return notify_fail("这里没有这个人。\n");  
      if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
     message_vision(YEL"$N运起回阳大法，只见一道金光，罩过$N身上。\n"NOR,obj);
     if( obj->is_ghost() )
     {
         obj->reincarnate();
         message_vision(HIB"三魂六魄重新回到$N体内。\n",obj);
     }
      
      if (obj->query("id")=="jiuer") obj->set("max_qi",99999);
        obj->set("qi",(int)obj->query("max_qi"));
        obj->set("eff_qi",(int)obj->query("max_qi"));
        obj->set("jing",(int)obj->query("max_jing"));
        obj->set("eff_jing",(int)obj->query("max_jing"));
        obj->set("neili", (int)obj->query("max_neili"));
        obj->clear_condition();
               
     message_vision(HIM"$N马上浑身充满了力量！\n"NOR,obj);              
     return 1;
}

int do_pace(string arg) {
       object me,obj;
       me=this_player();
       if (!arg) return notify_fail("谁？\n");
       if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("这里没有这个人。\n");
       if(!me->is_fighting(obj))
                return notify_fail("你们没在打架！\n");

       me->remove_killer(obj);
       me->remove_enemy(obj);
       obj->remove_killer(me);
       obj->remove_enemy(me);
       message_vision(HIG"$N连连摆手，对$n说：“别打了嘛。”\n"NOR,
                       me,obj);

       return 1;
}

int do_back(string arg)
{
        object me, obj;


        if( !arg )
                return notify_fail("你想把谁送走？\n");
        if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("这里没有这个人。\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
        if(obj == this_player())
                return notify_fail("自己送自己？有病！\n");
        message_vision(CYN"$N手指向下一点，把$n送回了武庙。\n"
NOR,this_player(),obj);
        obj->move("/d/city/wumiao");    
        return 1;
}

int do_hun(string arg)
{
        object me, obj;
        int flag=0;
        if( !arg )
                return notify_fail("你想弄昏谁？\n");
        if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("这里没有这个人。\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
        message_vision(HIR"$N拿出一根闷棍，把$n打得昏了过去。\n"NOR,
                       this_player(),obj);
        if (obj->query("env/immortal"))  
            flag=1; 
        obj->delete("env/immortal"); 
        obj->unconcious();    
        if (flag) obj->set("env/immortal",1); 
        return 1;
}

int do_tear(string arg)
{
	object me = this_player();
        if (!id(arg))
		return notify_fail("你要撕什么？\n");

        message_vision("$N把神秘物品撕得粉碎。\n", me);

        destruct(this_object());
        return 1;
}

int remov(string str)
{
  string ob, player;
  object obj,npc;
  seteuid(geteuid());

  if (sscanf(str,"%s from %s", ob, player) != 2)
    return 0;

  if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if (!(npc = present(player, environment (this_player()))))
        return notify_fail ("[MYST]: 没这个人\n");
  
  obj=present(ob, npc);

  if(!obj)
    return notify_fail ("这里没有那种东东\n");
  else {
    message_vision ("$N让" + npc->name() + "脱下$n。\n", this_player(), obj);
    obj->move(this_player());
    obj->move(npc);
    return 1;
  }
}

int steal(string str)
{
  string ob, player;
  object obj, npc, me;

  seteuid(geteuid());

  me = this_player();
  if (sscanf(str,"%s from %s", ob, player) != 2)
    return 0;
	if(player == "jiuer") return notify_fail("想偷酒儿的东西，下辈子吧。\n");
  npc = find_player (player);
  /*if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if ( !(npc = present(player, environment (me))) )
        return notify_fail ("没这个"+str+"\n");
   if(wiz_level(npc)>4) return notify_fail("想偷大神的东西，下辈子吧。\n");*/
  if (!(obj=present(ob, npc)))
    return notify_fail ("没这个东西"+str+"\n");

  obj->move(me);

  write("你偷了"+npc->name(1)+"的"+obj->short()+"。\n");
  // CHANNEL_D->do_channel(this_object(), "rumor*", "看到有人鬼鬼祟祟地从" + npc->name(1)
  //		+ "身上偷走了" + obj->short() + "。");

  return 1;
}

int whereis(string arg)
{
  object where, me;
  object *ob;
  string msg;
  int i;

  me = this_player();
  if (arg) {
	if (find_player(arg))
    where = environment(find_player(arg));
    if (!where) return notify_fail ("他在虚无缥缈间。\n");
	"/cmds/std/look"->look_room(me, where);
	return 1;
  }
  else {
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %s\n",
                       msg, ob[i]->name(1), ob[i]->query("id"),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %s\n",
                       msg, ob[i]->name(1), ob[i]->query("id"),
                       file_name(where));
      }
  }
  write (msg);
  return 1;
}

int full(string str)
{
  int max;
  object me;

  if (!geteuid()) seteuid (getuid());
  if(!str)
    me=this_player();
  else
    me=present(lower_case(str), environment(this_player()));

  if (!me) return notify_fail ("[MYST]: full error: 找不到"+str+"\n");
	me->reincarnate();
  max = me->query("eff_jingli");
  me->set("jingli",max);
  max = me->query("max_jing");
  me->set("eff_jing",max);
  me->set("jing",max);
  max = me->query("max_qi");
  me->set("eff_qi",max);
  me->set("qi",max);
  max = me->query("max_neili");
  me->set("neili",max);
  max = me->max_food_capacity();
  me->set("food",max);
  max = me->max_water_capacity();  
  me->set("water",max);
	if (wizardp(me))
		me->clear_condition();

	if (me != this_player())
  message_vision( "$N对着$n念起不死族回复咒文 [32;1m撒拉 伊克 庵修姆 [37;0m\n",
                  this_player(), me);

  return 1;
}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[MYST]: wave <多少钱> <钱币种类>\n");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail("你摇了半天却什么也没有出来。\n");
        if( amount < 1 )
                return notify_fail("你摇了半天却什么也没有出来。\n");

        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf("$N使劲的掏口袋，突然从袋子里掏出%s%s%s。\n",
                        chinese_number(amount),
                        n_money->query("base_unit"),
                        n_money->query("name")),
                this_player());
        return 1;
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail ("[MYST]: 你想让谁 PK 谁啊\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("找不到 "+st1+" 这个生物.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("找不到 "+st2+" 这个生物.\n");
	if(st1 == "jiuer" || st2 == "jiuer") return notify_fail("想让酒儿打架，下辈子吧。\n");

/*	message_vision("$N用美丽泳装的美丽法\力, 让"+
		ob1->name()+"跟"+ob2->name()+"开始互相瓯斗。",
		this_player());*/
        ob1->kill_ob(ob2);
        return 1;
}

int do_give (string arg)
{
  object me, ob, who;
  string wiz, obs, whos;

	if (!arg) return 0;
  me = this_player();
  wiz = wizhood (me);
  if (sscanf(arg, "%s to %s", obs, whos) != 2)
    return 0;
  if (obs != "myst" && obs != "myst") return 0;
  
  write ("my level : "+wiz_level(me)+"\n");
  if (wiz_level(me) > 2)
  if ((wiz = SECURITY_D->get_boss(whos)) == "" || (wiz != me->query("id"))) {
    write ("本神秘物品不能给亲戚以外的人。\n");
    return 1;
  }

  ob = present ("myst", me);
  if (!ob) write ("你没有这样东西。\n");
  who = find_player(whos);
  if (!who) write ("没有这个人。\n");
  if (ob && who) {
    ob->move (who);
    message_vision ("$N给$n一件神秘物品。\n", me, who);
  }
  return 1;
}

int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("[MYST]: wakeup error, wakeup <someone>\n");

  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("[MYST]: wakeup error, 没有"+str+"\n");
  who->remove_call_out("revive");
  who->clear_condition();
  who->revive();
  who->reincarnate();
  return 1;
}

int query_autoload()
{
  if (wizardp(this_player()))
    return 1;
  else return 0;
}

int force_quit (string str)
{
  object ob, usr;

  seteuid(getuid());
  if (!str) return notify_fail ("[MYST]: Hey you! 你想让谁 quit 啊\n");

  
  if (!(ob=find_player(str)))
    return notify_fail ("[MYST]: 没这个人("+str+")\n");

  if (objectp (ob))
    destruct( ob );
  else
    write ("[MYST]: cannot force quit\n");
  return 1;
}

int do_say(string arg)
{
	object me = this_player();

	tell_room(environment(me), CYN + arg + "\n"NOR);
	return 1;
}

int sort_user(object ob1, object ob2)
{
	string name1, name2;

	if( wiz_level(ob1) != wiz_level(ob2) )
		return wiz_level(ob2)
			- wiz_level(ob1);
	
	name1 = ob1->query("family/family_name");
	name2 = ob2->query("family/family_name");

	if (intp(name1)) name1 = "";
	if (intp(name2)) name2 = "";
	if (name1 > name2) return -1;
	if (name1 < name2) return 1;

	return (int)ob2->query("combat_exp") - (int)ob1->query("combat_exp");
}

mixed do_who(string arg)
{
	string str, *option;
	object *list, *ob;
	int i, ppl_cnt, cnt;
	int opt_long, opt_id, opt_wiz;
	object me=this_player();

	if( arg ) {
		option = explode(arg, " ");
		i = sizeof(option);
		while( i-- )
			switch(option[i]) {
				case "-l": opt_long = 1;	break;
				case "-i": opt_id = 1;		break;
				case "-w": opt_wiz = 1;		break;
				default:
					if( wizardp(me)
					&&	option[i][0]=='@' ) {
						RWHO_Q->send_rwho_q(option[i][1..sizeof(option[i])],
							me, opt_long);
						write("网路讯息已送出，请稍候。\n");
						return 1;
					}
					return notify_fail("指令格式：who [-l|-i|-w]\n");
			}
	}

	if( opt_long && !wizardp(me)) {
		if( (int)me->query("jing") < 30 )
			return notify_fail("你的精神太差了，没有办法得知其他玩家的详细资料。\n");
		me->receive_damage("jing", 30);
	}

    str = "◎ " + MUD_NAME + "\n";
	str += "—————————————————————————————————————\n";
	list = objects();
	i = sizeof(list);
	while (i--)
		if (userp(list[i])) {
			ob = ({ list[i] });
			break;
		}
	while (i--)
		if (userp(list[i])) ob += ({ list[i] });
	list = sort_array(ob, (: sort_user :));
	ppl_cnt = 0;
	cnt = 0;
	if( opt_long || opt_wiz ) {
		i = sizeof(list);
		while( i-- ) {
			// Skip those users in login limbo.
			if( !environment(list[i]) ) continue;
			//if( !me->visible(list[i]) ) continue;
			if( opt_wiz && !wizardp(list[i]) ) continue;
			str = sprintf("%s%12s%s%s\n",
				str,
				RANK_D->query_rank(list[i]),
				interactive(list[i])?" ":"*",
				list[i]->short(1)
			);
			if (interactive(list[i])) ppl_cnt++;
			cnt++;
		}
	} else {
		i = sizeof(list);
		while( i-- ) {
			// Skip those users in login limbo.
			if( !environment(list[i]) ) continue;
			//if( !me->visible(list[i]) ) continue;
			str = sprintf("%s%s%-10s%s",
				str,
				interactive(list[i])?" ":"*",
				opt_id ? capitalize(list[i]->query("id")): list[i]->name(1),
				cnt%7==6? "\n": ""
			);
			if (interactive(list[i])) ppl_cnt++;
			cnt++;
		}
		if( cnt%7 ) str += "\n";
	}
		
	str += "—————————————————————————————————————\n";
	str = sprintf("%s共有 %d 位使用者连线中，系统负担：%s\n* 表示断线中", str, ppl_cnt,
		query_load_average());

//	if( remote ) return str;

	me->start_more(str);
	return 1;
}

int do_look(string arg)
{
	int i;
	object *inv;
	mapping exits;
	string str, *dirs;
	object me = this_player();
	object env = environment(me);

	if( !env ) {
		write("你的四周灰蒙蒙地一片，什么也没有。\n");
		return 1;
	}
	str = sprintf( "%s - %s\n    %s%s",
		env->query("short"),
		wizardp(me)? file_name(env): "",
		env->query("long"),
		env->query("outdoors")? NATURE_D->outdoor_room_description() : "" );

	if( mapp(exits = env->query("exits")) ) {
		dirs = keys(exits);
		for(i=0; i<sizeof(dirs); i++)
			if( (int)env->query_door(dirs[i], "status") & DOOR_CLOSED )
				dirs[i] = 0;
		dirs -= ({ 0 });
		if( sizeof(dirs)==0 )
			str += "    这里没有任何明显的出路。\n";
		else if( sizeof(dirs)==1 )
			str += "    这里唯一的出口是 " + BOLD + dirs[0] + NOR + "。\n";
		else
			str += sprintf("    这里明显的出口是 " + BOLD + "%s" + NOR + " 和 " + BOLD + "%s" + NOR + "。\n",
				implode(dirs[0..sizeof(dirs)-2], "、"), dirs[sizeof(dirs)-1]);
	}
//	str += env->door_description();

	inv = all_inventory(env);
	for(i=0; i<sizeof(inv); i++) {
		if( inv[i]==me ) continue;
	//	if( !me->visible(inv[i]) ) continue;
		str += "  " + inv[i]->short() + "\n";
	}

	write(str);
	return 1;
}
