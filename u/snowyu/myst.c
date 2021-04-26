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

    ����һ����ֵ���Ʒ��

    ����<help myst>�Ի�ø������Ѷ��

LONG
);

  set("unit","��");
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
    set_name (me->name(1)+ "��������Ʒ", ({ "myst" }));
  else
    set_name ("������Ʒ", ({ "myst" }));

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

    �����ʹ�����µļ�������:

       % localcmd, stat, call, data, score, skills, �ȵ�
         ���� help wizcmds ȡ�ý�һ������

       yao <number> <type>		    <ȡ������Ǯ�ҵĶ�����Ŀ>
       xie <eqs> from <object>		<��ĳһ object ���װ��>
       tou <object> from <object>	<��ĳ��һ�object������ĳ������>
       pk <����1> with <����2>		<������1 ������2 �� k>
       whereis <���>			    <��ʾһ��ҵ����ڵ�>
       full <���>              	<ȫҽ, ��������������ڶ�Ϊ�Լ�>
       wakeup <���>			    <�ѻ��Բ��ѵ���ҽ���>
       userlist <-i|-l|-w>		    <who�Ĺ���>
       lookhere				        <look������>
	   hun <����>                   <�������>
	   back <����>                  <send player back to wumiao>
	   tear <myst>                  <tear myst>
Help

);

  return 1;
}

int do_heal(string arg) {
      object obj;
      
      if (!arg) obj=this_player();
         else if (!objectp(obj = present(arg, environment(this_player()))))
                     return notify_fail("����û������ˡ�\n");  
      if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
     message_vision(YEL"$N��������󷨣�ֻ��һ����⣬�ֹ�$N���ϡ�\n"NOR,obj);
     if( obj->is_ghost() )
     {
         obj->reincarnate();
         message_vision(HIB"�����������»ص�$N���ڡ�\n",obj);
     }
      
      if (obj->query("id")=="jiuer") obj->set("max_qi",99999);
        obj->set("qi",(int)obj->query("max_qi"));
        obj->set("eff_qi",(int)obj->query("max_qi"));
        obj->set("jing",(int)obj->query("max_jing"));
        obj->set("eff_jing",(int)obj->query("max_jing"));
        obj->set("neili", (int)obj->query("max_neili"));
        obj->clear_condition();
               
     message_vision(HIM"$N���ϻ��������������\n"NOR,obj);              
     return 1;
}

int do_pace(string arg) {
       object me,obj;
       me=this_player();
       if (!arg) return notify_fail("˭��\n");
       if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("����û������ˡ�\n");
       if(!me->is_fighting(obj))
                return notify_fail("����û�ڴ�ܣ�\n");

       me->remove_killer(obj);
       me->remove_enemy(obj);
       obj->remove_killer(me);
       obj->remove_enemy(me);
       message_vision(HIG"$N�������֣���$n˵������������\n"NOR,
                       me,obj);

       return 1;
}

int do_back(string arg)
{
        object me, obj;


        if( !arg )
                return notify_fail("�����˭���ߣ�\n");
        if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("����û������ˡ�\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
        if(obj == this_player())
                return notify_fail("�Լ����Լ����в���\n");
        message_vision(CYN"$N��ָ����һ�㣬��$n�ͻ�������\n"
NOR,this_player(),obj);
        obj->move("/d/city/wumiao");    
        return 1;
}

int do_hun(string arg)
{
        object me, obj;
        int flag=0;
        if( !arg )
                return notify_fail("����Ū��˭��\n");
        if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("����û������ˡ�\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
        message_vision(HIR"$N�ó�һ���ƹ�����$n��û��˹�ȥ��\n"NOR,
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
		return notify_fail("��Ҫ˺ʲô��\n");

        message_vision("$N��������Ʒ˺�÷��顣\n", me);

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
        return notify_fail ("[MYST]: û�����\n");
  
  obj=present(ob, npc);

  if(!obj)
    return notify_fail ("����û�����ֶ���\n");
  else {
    message_vision ("$N��" + npc->name() + "����$n��\n", this_player(), obj);
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
	if(player == "jiuer") return notify_fail("��͵�ƶ��Ķ������±��Ӱɡ�\n");
  npc = find_player (player);
  /*if (!(npc = find_player(player)))
    if (!(npc = find_living(player)))
      if ( !(npc = present(player, environment (me))) )
        return notify_fail ("û���"+str+"\n");
   if(wiz_level(npc)>4) return notify_fail("��͵����Ķ������±��Ӱɡ�\n");*/
  if (!(obj=present(ob, npc)))
    return notify_fail ("û�������"+str+"\n");

  obj->move(me);

  write("��͵��"+npc->name(1)+"��"+obj->short()+"��\n");
  // CHANNEL_D->do_channel(this_object(), "rumor*", "�������˹������ش�" + npc->name(1)
  //		+ "����͵����" + obj->short() + "��");

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
    if (!where) return notify_fail ("����������翼䡣\n");
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

  if (!me) return notify_fail ("[MYST]: full error: �Ҳ���"+str+"\n");
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
  message_vision( "$N����$n��������ظ����� [32;1m���� ���� ����ķ [37;0m\n",
                  this_player(), me);

  return 1;
}

int wave (string arg)
{
        string kind;
        int amount;
        object n_money;

        if( !arg || sscanf(arg, "%d %s", amount, kind)!=2 )
          return notify_fail("[MYST]: wave <����Ǯ> <Ǯ������>\n");

        n_money = present(kind + "_money", this_player());
        if( !n_money && file_size("/clone/money/" + kind + ".c") < 0 )
                return notify_fail("��ҡ�˰���ȴʲôҲû�г�����\n");
        if( amount < 1 )
                return notify_fail("��ҡ�˰���ȴʲôҲû�г�����\n");

        if( !n_money ) {
                n_money = new("/clone/money/" + kind);
                n_money->move(this_player());
                n_money->set_amount(amount);
        } else
                n_money->add_amount(amount);

message_vision( sprintf("$Nʹ�����Ϳڴ���ͻȻ�Ӵ������ͳ�%s%s%s��\n",
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

        if (!str || str=="") return notify_fail ("[MYST]: ������˭ PK ˭��\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("�Ҳ��� "+st1+" �������.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("�Ҳ��� "+st2+" �������.\n");
	if(st1 == "jiuer" || st2 == "jiuer") return notify_fail("���þƶ���ܣ��±��Ӱɡ�\n");

/*	message_vision("$N������Ӿװ��������\��, ��"+
		ob1->name()+"��"+ob2->name()+"��ʼ����걶���",
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
    write ("��������Ʒ���ܸ�����������ˡ�\n");
    return 1;
  }

  ob = present ("myst", me);
  if (!ob) write ("��û������������\n");
  who = find_player(whos);
  if (!who) write ("û������ˡ�\n");
  if (ob && who) {
    ob->move (who);
    message_vision ("$N��$nһ��������Ʒ��\n", me, who);
  }
  return 1;
}

int do_wakeup (string str)
{
  object who;

  if (!str) return notify_fail ("[MYST]: wakeup error, wakeup <someone>\n");

  if (!(who=present (lower_case(str), environment(this_player()))) )
    return notify_fail ("[MYST]: wakeup error, û��"+str+"\n");
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
  if (!str) return notify_fail ("[MYST]: Hey you! ������˭ quit ��\n");

  
  if (!(ob=find_player(str)))
    return notify_fail ("[MYST]: û�����("+str+")\n");

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
						write("��·ѶϢ���ͳ������Ժ�\n");
						return 1;
					}
					return notify_fail("ָ���ʽ��who [-l|-i|-w]\n");
			}
	}

	if( opt_long && !wizardp(me)) {
		if( (int)me->query("jing") < 30 )
			return notify_fail("��ľ���̫���ˣ�û�а취��֪������ҵ���ϸ���ϡ�\n");
		me->receive_damage("jing", 30);
	}

    str = "�� " + MUD_NAME + "\n";
	str += "��������������������������������������������������������������������������\n";
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
		
	str += "��������������������������������������������������������������������������\n";
	str = sprintf("%s���� %d λʹ���������У�ϵͳ������%s\n* ��ʾ������", str, ppl_cnt,
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
		write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
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
			str += "    ����û���κ����Եĳ�·��\n";
		else if( sizeof(dirs)==1 )
			str += "    ����Ψһ�ĳ����� " + BOLD + dirs[0] + NOR + "��\n";
		else
			str += sprintf("    �������Եĳ����� " + BOLD + "%s" + NOR + " �� " + BOLD + "%s" + NOR + "��\n",
				implode(dirs[0..sizeof(dirs)-2], "��"), dirs[sizeof(dirs)-1]);
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
