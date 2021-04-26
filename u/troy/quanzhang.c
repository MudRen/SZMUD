//this file was stole by me from other wizs:)
//original crystal.c now baobei.c
#include <ansi.h>
#include <weapon.h>
#include <login.h>
inherit STAFF;
inherit F_SAVE;
inherit F_AUTOLOAD;
//inherit F_DAMAGE;

int query_autoload() { return 1; }

void create()
{
        set_name(YEL"ľ��"NOR, ({ "quan zhang","staff","zhang"}) );
        set_weight(20);
        if (clonep())
		set_default_object(__FILE__);
	else
	 {
        set("long", "\t����һ�����Զ���������ľ�̣������Զ�(ding)��
        ��(kickout)���ָ�(heal)������(whereis)����(wakeup)����(hun)��
        ȥ���˼�(leadme)��Ȱ��(peace)���䣨bian��������si��
        ����mie) ���ã�she)��\n");
	set("unit","��");
       set("value", 0);
       set("material", "steel");
       set("wield_msg", HIW"$N���һ��$n"+HIW+"�������У���ʱ���Ϸ����˵���"+HIY+"��⡣\n"NOR);
       set("unwield_msg", HIW"$N�����е�$n����������\n"NOR);
       }
       init_staff(350);
        setup();
}

void init()
{
        object me,ob;
        me =this_player();
        ob=this_object();
        if (this_player()->query("id")!="troy")
        	{
        	message_vision(HIW"������һ����˵�������ⲻ����Ķ��������á���\n"NOR,me);
       		message_vision(HIY"ľ��ͻȻ��ʧ�ˡ�\n"NOR,me);
       		destruct(ob);
       		return 0;
       		}
           else
           {
           add_action("do_kickout","kickout");
       	add_action("do_ding","ding");
       	add_action("do_sou","sou");
       	add_action("do_whereis", "whereis");
       	add_action("do_wakeup", "wakeup");
        add_action("do_bian","bian");
       	add_action("do_hun","hun");
       	add_action("do_peace","peace");
       	add_action("do_heal","heal");
	add_action("do_she","she");
	add_action("do_leadme","leadme");
	add_action("do_si","si");
	add_action("do_huo","huo");
	add_action("do_mie","mie");
	}
       		
}




int do_she(string arg)
{
	if (!arg)
		return notify_fail("��Ҫ����ʲô��/n");
	if (arg=="hidden")
		{
		message_vision(HIM"$N��ľ�����Լ���ͷ��ת��һȦ��$NͻȻ��ȥ�����Σ���ʧ����Ӱ���٣�\n"NOR,this_player());
		this_player()->set("env/invisibility",1);
		return 1;
		}
	if (arg=="nodie")
		{
		message_vision(HIM"$N��ľ�����Լ���ͷ��ת��һȦ����ʱ$N���˲���֮��\n"NOR,this_player());              
		this_player()->set("env/immortal",1);
		return 1;
	}
	return 0;
	}


int do_mie (string item)
{
	object obj;
	object me;
	me=this_player();
	if (!item)
		return notify_fail("��Ҫ��˭�����ˣ�");
	 if(!objectp(obj = present(item, environment(this_player()))))
					 return notify_fail("����û������ˡ�\n");
		  if (!obj) obj = present(item, me);
		  if (!obj) obj = find_object( resolve_path(me->query("cwd"), item) );
		  if (!obj) return notify_fail("û���������....��\n");
	
	message_vision(RED"$N��ľ�ȵ���һ��"+obj->query("name")+",һ�����̹���ʲô��û�ˣ�\n"NOR,this_player());
	destruct(obj);
	return 1;
	}

int do_huo(string target)
{
	         object deadman = present (target,environment(this_player()));
		  mapping skill_status, learned_status;
		  string *sname;
		  int i,new_exp,skill_amount;
		object me=this_player();
		  if( !target )
					 return notify_fail("����Ҫ��˭������\n");
		  if( me->is_fighting() || me->is_busy() )
					 return notify_fail("����æ���أ�\n");
		
		if ( !deadman->is_ghost() )
			return notify_fail(deadman->query("name")+"�Ѿ��������,�ò�����ȡ�\n");
                        		
                message_vision( HIY"$N����һ��ľ�ȣ�"+deadman->query("name")+"�漣��Ļ��˹������书������\n"NOR, me);
	           
                		deadman->reincarnate();
                		learned_status = deadman->query_learned();
                		if ( mapp(skill_status = deadman->query_skills()) )
                		{
                        		sname = keys(skill_status);
                        		for(i=0; i<sizeof(skill_status); i++) 
                        		{
                                		skill_amount = (skill_status[sname[i]]+1) * (skill_status[sname[i]]+1) / 2;
		                                if( !mapp(learned_status) ) learned_status = ([ sname[i] : skill_amount ]);
                     			           else {
                                        			if( learned_status[sname[i]]  < skill_amount )
                                                			learned_status[sname[i]] += skill_amount;
                                        			else {
                                                			learned_status[sname[i]] -= skill_amount;                                                                    - (skill_status[sname[i]]) * (skill_status[sname[i]]);
                                                			deadman->set_skill(sname[i], skill_status[sname[i]]+1);
                                        				}
                                			}
                        		}
                		}

                		new_exp = (int)deadman->query("combat_exp") / 99;
                		new_exp = new_exp > 5000 ? 5000 : new_exp;
                		deadman->add("combat_exp", new_exp);
                		deadman->set("qi",1000); 
                		deadman->set("eff_qi",1000); 
                		deadman->set("jing",1000); 
                		deadman->set("eff_jing",1000); 
                		deadman->set("jingli",1000); 
                		deadman->add("death_count", -1);
                		deadman->add("death_times",-1);
		           	deadman->move(environment(me));
           			return 1;       
        }
	

int do_si(string arg)
{
	
       object obj = present (arg,environment(this_player()));
       if (!arg)
       	return notify_fail("�������˭");
       if (this_player()->query("id")!="troy")
       return notify_fail(HIW"��û�����Ȩ��!\n"NOR);
	obj->delete("env/invisibility");
	obj->delete("env/immortal"); 
	obj->die();
	write(HIC"�������Ѿ������Լ�����!\n"NOR); 
	tell_object(obj,RED"��ȥ����!\n"NOR);
	return 1; 
}

int do_bian(string arg)
{
     	int amount;
     	object gold;
     	if (!arg)
     	 	return notify_fail("�����ʲô��\n");
     	if( !arg || sscanf(arg, "%d gold", amount) != 1 )
                return notify_fail("������\n");
     	gold=new("/clone/money/gold");
	gold->set_amount(amount);
	gold->move(this_player());
	message_vision(HIY"$N�����һЩ�ƽ�~��\n"NOR,this_player());
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
        message_vision(HIR"$N�ó�һ��ľ�ȣ���$n��û��˹�ȥ��\n"NOR,this_player(),obj);
        if (obj->query("env/immortal"))  
            flag=1; 
        obj->delete("env/immortal"); 
        obj->unconcious();    
        if (flag) obj->set("env/immortal",1); 
        return 1;
}

int do_whereis(string arg)
{
  object where, me;
  object *ob;
  string msg;
  int i;

  me = this_player();
  if (arg) {
        if (find_player(arg))
    where = environment(find_player(arg));
    if (!where) return notify_fail ("��������Ʈ��䡣\n");
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


int do_wakeup(string arg)
{
        object me, obj;

        me = this_player();

        if( !arg )
                return notify_fail("����Ū��˭��\n");
        if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("����û������ˡ�\n");
        if( !obj->is_character() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
        message_vision(HIR"$Nһ������$nɿ��ȥ��$n��ѽһ�����ˡ�\n"
NOR,this_player(),obj);
	obj->revive();   
	return 1;
}

int do_kickout(string arg)
{
        object me, obj;


        if( !arg )
                return notify_fail("�����˭���ߣ�\n");
        if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("����û������ˡ�\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
        if(obj == this_player())
                return notify_fail("���Լ����в���\n");
        message_vision(CYN"$N����һ�ţ���������$n��ƨ�ɡ�\n"
NOR,this_player(),obj);
        obj->move("/d/death/block");    
        return 1;
}

int do_ding(string arg)
{
        object me, obj;


        if( !arg )
                return notify_fail("���붨˭��\n");
        if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("����û������ˡ�\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");

        if(obj == this_player())
                return notify_fail("�� suicide ָ���ȽϿ�:P��\n");
        message_vision(HIY"$N��һָ�����õ���$n������Ѩ��$n��ʱ�������á�\n"
NOR,this_player(),obj);
        obj->start_busy(200);    
        return 1;
}

int do_sou(string arg)
{
        object me, obj,env;
        string from,item;

        me=this_player();

        if( !arg ) return notify_fail("��Ҫʲô������\n");

        if( !sscanf(arg, "%s from %s", item, from)==2 )
               return notify_fail("��͵���Ķ������������õģ�\n");

        if(!objectp(env = present(from, environment(me))))
              return notify_fail("����û������ˡ�\n");

        if(!objectp(obj = present(item,env)))
           return notify_fail(env->query("name")+"û������������\n");
        obj->move(me);
        message_vision(HIY"\n$Nһ���֣���ৡ���һ����$n�������ó���"+obj->query("name")
                       +"��\n"NOR,this_player(),env);
        return 1;
}


int do_leadme(string arg)
{
        object me, obj;

        if( !arg )
                return notify_fail("ȥ���\n");
        
        if( file_size("/u/"+arg + "/workroom.c") <= 0 )
                return notify_fail("����homeless!\n");

         if (this_player()->move("/u/"+arg+"/workroom") )
             
            message_vision(HIC"\n$N���һ�������ѣ������ˣ�\n"NOR,
                       this_player());

            else tell_object(this_player(),"����homeless!\n");
         
       return 1;
}



int do_peace(string arg) {
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
       message_vision(HIG"$N�������֣���$n˵��������������\n"NOR,
                       me,obj);

       return 1;
}

int do_heal(string arg) {
      object obj;
      
      if (!arg) obj=this_player();
         else if (!objectp(obj = present(arg, environment(this_player()))))
                     return notify_fail("����û������ˡ�\n");  
      if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("�����һ�㣬�ǲ����ǻ��\n");
     message_vision(HIM"$N��������񹦣�ֻ��һ����⣬����$N���ϡ�\n"NOR,obj);
     if( obj->is_ghost() )
     {
         obj->reincarnate();
         message_vision(HIB"�����������»ص�$N���ڡ�\n",obj);
     }
      
      if (obj->query("id")=="dca") obj->set("max_qi",99999);
        obj->set("qi",(int)obj->query("max_qi"));
        obj->set("eff_qi",(int)obj->query("max_qi"));
        obj->set("jing",(int)obj->query("max_jing"));
        obj->set("eff_jing",(int)obj->query("max_jing"));
	obj->set("jingli",(int)obj->query("max_jing"));
        obj->set("eff_jingli",(int)obj->query("max_jing"));
        obj->set("neili", (int)obj->query("max_neili"));
        obj->clear_condition();
               
     message_vision(HIM"$N���ϻ��������������\n"NOR,obj);              
     return 1;
}
