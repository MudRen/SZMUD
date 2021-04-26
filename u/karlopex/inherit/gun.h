//Cracked by lisser
//gun.h

#include <ansi.h>
#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

private int shoot_result(object me, object target, string limbs, int str);
mapping limbs = ([
	"zs1":({"ͷ��", "����", "�ؿ�", "����"}),
	"zs2":({"����", "����", "����", "С��", "����"}),
	"qs":({"���", "�Ҽ�", "���", "�ұ�", "����", "����", "����", "����", "���", "�ҽ�", "���", "�Ҷ�"}),
]);	
mapping default_dirs = ([
        "north":(["z":"��","f":"��"]),
        "south":(["z":"��","f":"��"]),
        "east":(["z":"��","f":"��"]),
        "west":(["z":"��","f":"��"]),
        "northup":(["z":"��","f":"��"]),
        "southup":(["z":"��","f":"��"]),
        "eastup":(["z":"��","f":"��"]),
        "westup":(["z":"��","f":"��"]),
        "northdown":(["z":"��","f":"��"]),
        "southdown":(["z":"��","f":"��"]),
        "eastdown":(["z":"��","f":"��"]),
        "westdown":(["z":"��","f":"��"]),
        "northeast":(["z":"����","f":"����"]),
        "northwest":(["z":"����","f":"����"]),
        "southeast":(["z":"����","f":"����"]),
        "southwest":(["z":"����","f":"����"]),
        "up":(["z":"��","f":"��"]),
        "down":(["z":"��","f":"��"]),
        "out":(["z":"��","f":"��"]),
        "enter":(["z":"��","f":"��"]),
]);
private string ffx;
void init()
{
	add_action("do_reload", "reload");
}

varargs void init_gun(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag );
	set("skill_type", "archery");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

int do_reload(string arg)
{
	object me, ob, arrow, load_arrow;
	string str;	

	me = this_player();
	ob = this_object();

	if (!arg || !objectp(arrow = present(arg, me)) ) 
		return notify_fail("�㲻��ǹ��װ�ӵ�������װʲô��\n");
	
	if ( arrow->query("weapon_type") != "bullet" )
		return notify_fail("������ÿ����Ʒ�����Ե��ӵ��õġ�\n");
	
	if ( ob->query_temp("arrow_load") == "loaded")
		return notify_fail("���Ѿ�װ���ӵ��ˡ�\n");

	load_arrow = new(base_name(arrow));

        if( arrow->query("poison_type") ) {
                ob->set("poison_applied", arrow->query("poison_applied"));
                ob->set("poison_type", arrow->query("poison_type"));
        }

	message_vision("$N����ǹ�ϵĿյ�ϻж�£����µ�$nװ�ϡ�\n",me, load_arrow);
	
	str = ob->query("org_long")+"�����Ѿ�װ��һ���µ��ӵ�ϻ��������"+chinese_number(load_arrow->query("shu"))+load_arrow->query("unit")+load_arrow->name()+"��\n";
	ob->set("long", str);

	ob->set_temp("arrow_load", "loaded" );
	ob->set_temp("arrow_amount", 10 );        
	if (arrow->query_amount() > 1)
                arrow->add_amount(-1);
        else destruct(arrow);
        add_action("do_pull","miao");
	return 1;
}
	
int do_pull(string arg)
{
        object me, ob, env, env2, *inv;
        string enemy, dir, dest, target, disp, targets = "";
        mapping exit;
        int num, i, j;

        me = this_player();
        ob = this_object();
        env = environment(me);
        
        if( (string)ob->query("equipped")!="wielded" )
                return notify_fail("ǹ�������㱳���ء�\n");
                
        if (!arg || arg == "" ){
       	        if( objectp(ob->query_temp("pulled")) )
	                return notify_fail("���Ѿ��鶨��"+(ob->query_temp("pulled"))->name()+"��\n");
                return notify_fail("�����������\n");
        }else if( sscanf(arg, "%s to %d", dir, num) == 2 ){
		if (dir == "enter" || dir == "out" || dir == "up" || dir == "down" || !default_dirs[dir])
			num = 1;
		else if(num > 5) return notify_fail("����̫Զ���ѻ���ǹû�а취������\n");;
		env2 = env;
        	for(j=0;j<num;j++)
        	{
			disp = "";
		        if( !mapp(exit = env2->query("exits")) || undefinedp(exit[dir]) ){
				message_vision(HIG "\nֻ��$N����$n"+HIG+"��"+target+"������ȥ������\n" NOR,me,ob);
				tell_object(me,HIG"����һ��"+target+"���򣬷���"+chinese_number(j)+"�������������\n"+targets+"\n"NOR);
				return 1;
			}
		        dest = exit[dir];
		        if( !(env2 = find_object(dest)) ){
        			call_other(dest, "???");
				message_vision(HIG "\nֻ��$N����$n"+HIG+"��"+target+"������ȥ������\n" NOR,me,ob);
				tell_object(me,HIG"����һ��"+target+"���򣬷���"+chinese_number(j)+"�������������\n"+targets+"\n"NOR);
				return 1;
			}
			if( !default_dirs[dir] )
				 target = env2->query("short");
			else
				 target = default_dirs[dir]["z"];
			inv = all_inventory(env2);
			for(i=0; i<sizeof(inv); i++) {
				if( !inv[i]->is_character() ) continue;
				disp += inv[i]->short(1)+"\n";
			}
			if (sizeof(disp) > 0)
				targets += HIG"��"+chinese_number(j+1)+"�����䣺"+env2->query("short")+HIG"���������������\n"NOR + disp;
			else targets += HIG"��"+chinese_number(j+1)+"�����䣺"+env2->query("short")+HIG"������û�����\n"NOR;
		}        	
		message_vision(HIG "\nֻ��$N����$n"+HIG+"��"+target+"������ȥ������\n" NOR,me,ob);
		tell_object(me,HIG"������һ��"+target+"���򣬷���"+chinese_number(j)+"�������������\n"+targets+"\n"NOR);
		return 1;
        }else{
                if( sscanf(arg, "%s at %s", enemy, dir) != 2 )
	                if( sscanf(arg, "%s", dir) != 1 )
        	        return notify_fail("�����ʽ: miao <����> <ĳ��>��\n");

	        if( dir && !enemy ) return notify_fail("�㶨�����ƣ���Ŀ��������"+default_dirs[dir]["z"]+"����\n");
	        else if( !dir ) return notify_fail("����̫�������Ӳ��˾ѻ���ǹ��������");
	        else{
			if (dir == "enter" || dir == "out" || dir == "up" || dir == "down" || !default_dirs[dir])
				num = 1;
			else num = 5;
			env2 = env;
	        	for(j=0;j<num;j++)
	        	{
			        if( !mapp(exit = env2->query("exits")) || undefinedp(exit[dir]) ) {
			                if( query_verb() == "miao")
			                        return notify_fail(env2->query("short")+"û��"+default_dirs[dir]["z"]+"�����·�ˣ�����Ҳû���á�\n");
			                else
			                        return 0;
			        }
			        dest = exit[dir];
			        if( !(env2 = find_object(dest)) ){
                			call_other(dest, "???");
                			return notify_fail("û������ط���û�취��׼��\n");	        		
				}
				if( !default_dirs[dir] )
					 target = env2->query("short");
				else
					 target = default_dirs[dir]["z"];
				inv = all_inventory(env2);
				for(i=0; i<sizeof(inv); i++) {
					if( !inv[i]->is_character() ) continue;
					if( inv[i]->query("id") != enemy ) continue;		
					else{
						ob->set_temp("pulled", inv[i]);
						ob->set_temp("pull-r", env2);
						ob->set_temp("miao-dir", env);
						if (!default_dirs[dir]) ffx = env->query("short");
						else ffx = default_dirs[dir]["f"];
						message_vision(HIG "\nֻ��$N����$n"+HIG+"����"+target+"�ķ�����ȥ������\n" NOR,me,ob);
						tell_object(me,HIG"�������"+inv[i]->name()+"��"+(inv[i]->query("gender")=="Ů��"?"��":"��")+"Ŀǰ��"+chinese_number(j + 1)+"�����"+env2->query("short")+HIG"�����ڡ�\n"NOR);
					        add_action("do_shoot","shoot");
	        				return 1;
					}					
				}
			}
			return notify_fail("������˲����⼸�������\n");
		}
	}
}

int do_shoot()
{
        object me, victim, ob, env, obj, arrow, dest, where;
        string enemy, dir, target, limb, str;
        mapping exit;

        me = this_player();
        ob = this_object();
	victim = ob->query_temp("pulled");
	
        env = environment(me);
	dest = ob->query_temp("pull-r");
         if(!env) return notify_fail("������Ҳ�䲻�ˡ�\n");

 	if ( ob->query_temp("arrow_load") != "loaded" )
		return notify_fail("��û���ӵ�����ô��\n");
		
        if( !ob->query_temp("pulled") )
                return notify_fail("��û��׼��ô��\n");		

	if(environment(victim) != dest)
		return notify_fail("���Ŀ���Ѿ��뿪�ˡ�\n");
		
	if(env != ob->query_temp("miao-dir"))
		return notify_fail("��ĽǶ��Ѿ����ˣ���Ҫ������׼��\n");

	if( ob->query("shoot_msg") )
		message_vision(ob->query("shoot_msg"), me);
	else
		message_vision(HIY"\n$Nʳָһ���������ء���һ��������\n" NOR, me);

	ob->delete_temp("miao-dir");
	ob->delete_temp("pull-r");
	tell_object(ob->query_temp("pulled"),HIR "\n��ֻ�������ء���һ����һ��С���弤��ֱ�������������\n" NOR);
	if ( me->query("qiangfa") > 100 && random(me->query("qiangfa")) > me->query("qiangfa") / 2 ){
		limb = limbs["zs1"][random(sizeof(limbs["zs1"]))];
		shoot_result(me, ob->query_temp("pulled"), limb, 1);
	}else if ( me->query("qiangfa") > 75 && random(me->query("qiangfa")) > me->query("qiangfa") / 4 ){
		limb = limbs["zs2"][random(sizeof(limbs["zs2"]))];
		shoot_result(me, ob->query_temp("pulled"), limb, 2);
	}else limb = limbs["qs"][random(sizeof(limbs["qs"]))];
	ob->delete_temp("pulled");
	ob->add_temp("arrow_amount",-1);
	if (ob->query_temp("arrow_amount") > 0){
		str = ob->query("org_long")+"�����Ѿ�װ��һ���ӵ�ϻ�����滹��"+chinese_number(ob->query_temp("arrow_amount"))+"�Ų�ǹ�ӵ���\n";
		ob->set("long", str);
        	remove_action("do_shoot","shoot");
        	add_action("do_pull","miao");
        }else if (present("bullet", me) && me->query("auto_reload_gun") == "auto"){
		str = ob->query("org_long");
		ob->set("long", str);
		ob->delete_temp("arrow_amount");
		ob->set_temp("arrow_load","empty");
        	remove_action("do_shoot","shoot");
        	remove_action("do_pull","miao");        	
        	return do_reload("gun-x");
        }else{
		str = ob->query("org_long")+"�����Ѿ�װ��һ���ӵ�ϻ�������ӵ��Ѿ������ˡ�\n";
		ob->set("long", str);
		ob->delete_temp("arrow_amount");
		ob->set_temp("arrow_load","empty");
        	remove_action("do_shoot","shoot");
        	remove_action("do_pull","miao");
	}
	return 1;
}

private int shoot_result(object me, object target, string limbs, int str)
{
	tell_object(target, HIR "\n���Ѿ��޷�������ֻ����"+limbs+"��λ��ʹ�������ܶ�Ѫ��\n" NOR);
        message("vision", HIR "\nֻ�������ء���һ����һ���ӵ���"+ffx+"�ķ��������"+target->name()+"��"+limbs+"���ӵ��򴩣������˺ܶ�Ѫ������\n" NOR,  environment(target), ({target}) );
	tell_object(me, HIR "\n��ԶԶ�ؿ���"+target->name()+"��"+limbs+"��λ��������ˣ�\n" NOR);
	if ( str == 1 ){
		if (getuid(me) == "lisser") tell_object(me,HIR"һǹ���У�����\n"NOR);
		target->receive_damage("qi", target->query("max_qi")*2, "��"+me->name()+"�þѻ���ǹ����"+limbs+"����");
		target->receive_wound("qi", target->query("max_qi")*2, "��"+me->name()+"�þѻ���ǹ����"+limbs+"����");
	}else if ( str == 2  ){
		if (getuid(me) == "lisser") tell_object(me,HIR"���и��˺���λ������\n"NOR);
		target->receive_damage("qi", target->query("max_qi")/2, "��"+me->name()+"�þѻ���ǹɱ����");
		target->receive_wound("qi", target->query("max_qi")/2, "��"+me->name()+"�þѻ���ǹɱ����");
		if ( me->query("qiangfa") < 500 && random(10) == 5){
			tell_object(me,BLK"���ǹ�������ˣ����ǻ��д���ߡ�\n"NOR);
			me->add("qiangfa",random(10));
		}
	}else{
		if (getuid(me) == "lisser") tell_object(me,HIR"δ����Ҫ����λ������\n"NOR);
		target->receive_damage("qi", target->query("max_qi")/4, "��"+me->name()+"�þѻ���ǹɱ����");
		target->receive_wound("qi", target->query("max_qi")/4, "��"+me->name()+"�þѻ���ǹɱ����");
		if ( me->query("qiangfa") < 200 && random(5) == 3){
			tell_object(me,BLK"���ǹ�������ˣ����ǻ�Ҫ����Ŭ����\n"NOR);
			me->add("qiangfa",random(5));
		}
	}
        return 1;
}
