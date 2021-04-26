// Code of ShenZhou
// look.c
// modified by sdong for biaoche, 12/23/98

#include <room.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int look_room(object me, object env);
int look_item(object me, object obj);
int look_living(object me, object obj);
int look_room_item(object me, string arg);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        object obj;
        int result;

        if( !arg ) result = look_room(me, environment(me));
        else if( (obj = present(arg, me)) || (obj = present(arg, environment(me)))) {
                if( obj->is_character() ) result = look_living(me, obj);
                else result = look_item(me, obj);
        } else result = look_room_item(me, arg);

        return result;
}

int look_room(object me, object env)
{
        int i;
        object *inv;
        mapping exits;
        string str, *dirs;

        if( !env ) {
                write("������ܻ����ɵ�һƬ��ʲôҲû�С�\n");
                return 1;
        }
        str = sprintf( "%s - %s\n    %s%s",
                env->query("short"),
                wizardp(me)? file_name(env): "",
                (file_name(env) == "/d/wizard/meeting_room" )?env->update_here():env->query("long"),
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
//      str += env->door_description();

        inv = all_inventory(env);
        for(i=0; i<sizeof(inv); i++) {
                if( inv[i]==me ) continue;
                if( !me->visible(inv[i]) ) continue;
                if( objectp(inv[i]->query("rider")) ) continue;
                else inv[i]->delete("rider");


                if( objectp(inv[i]->query("rided")) ) {
                        str += "  " + inv[i]->short() + "����" +
                        (inv[i]->query("rided"))->name() + "��";
                if( stringp(inv[i]->query_temp("exit_blocked")))
                                                                str += "������"+inv[i]->query_temp("exit_blocked")+
                                                                "ȥ��·";
                        str += "\n";
                }
                else {
                        if (stringp(inv[i]->query_temp("exit_blocked")))
                        str += "  " + inv[i]->short() + "������" + inv[i]->query_temp("exit_blocked")
                                +"ȥ��·\n";
                        else if( inv[i]->query_temp("riding") ) {
                                str += "  " + inv[i]->short() + "�����ڳ���\n";
                        }
						else if( inv[i]->query_temp("on_bantan") )
						{
                                str += "  " + inv[i]->short() + HIW+" < �� ̯ �� >\n"+NOR;
                        }
                        else if( inv[i]->query_temp("pending/heal_other") == me )
                                str += replace_string("  " + inv[i]->short() + "\n", me->name(), "��");
                        else
                                str += "  " + inv[i]->short() + "\n";
                        inv[i]->delete("rided");
                }
        }


        write(str);
        return 1;
}

int look_item(object me, object obj)
{
        mixed *inv;

        write(obj->long());
        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object() );
                message("vision", sprintf("�����У�\n  %s\n",
                        implode(inv, "\n  ") ), me);
        }
        return 1;
}

int look_living(object me, object obj)
{
        string str, limb_status, pro;
		int per;
        mixed *inv;
        mapping my_fam, fam;

        if(( me!=obj )&& (environment(me) == environment(obj))) {
          if ( !wizardp(me) || (wizardp(me) && !wizardp(obj) && !me->query("env/invisibility")) )
                message("vision", me->name() + "�������㿴����֪����Щʲô���⡣\n", obj);
        }

        str = obj->long();
  per = obj->query_per();
		
        pro = (obj==me) ? gender_self(obj->query("gender")) : gender_pronoun(obj->query("gender"));

        if( objectp(obj->query("rided")) ) 
                str += sprintf(pro +  "����" + (obj->query("rided"))->name() + "�ϡ�\n");

        if( (string)obj->query("race")=="����"
        &&      intp(obj->query("age")) )
                str += sprintf("%s������Լ%s���ꡣ\n", pro, 
                        chinese_number(
                        (obj->query("age")-SKILL_D("beauty")->reduce_age(obj)) / 10 * 10));

        if ((string) obj->query("gender") == "����" || (string) obj->query("gender") == "����")
        {
				if(wizardp(obj))
						str+=sprintf(HIY"%sȫ��ɢ����ҫ�۵Ľ�⣬����������֮������ࡣ\n"NOR,pro);
                if (per >=40) 
                        str +=pro+ HIG"����һ���������ȣ��ɷ���ǣ���ֹ������\n";
                if (per <= 39 && (per > 38))
                        str +=pro+ HIG"����������ˬ���Ǹ����棬�������ˡ�\n";
                if (per <= 38 && (per > 37))
                        str +=pro+ HIG"���ڷ����ʣ��������������������ٷ硣\n"NOR;
                if (per <= 37 && (per > 36))
                        str +=pro+ HIG"����Ʈ�ݳ������������ס�\n"NOR;
                if (per <= 36 && (per > 35))
                        str +=pro+ HIG"�����������񣬷�ױ����������������\n"NOR;
                if (per <= 35 && (per > 34))
                        str +=pro+ HIG"���ڷ�������Ŀ�����ǣ����˹�Ŀ������\n"NOR;
                if (per <= 34 && (per > 33))
                        str +=pro+ HIY"���ڷ����촽�����˿��Σ���ֹ�������ޡ�\n"NOR;
                if (per <= 33 && (per > 32))
                        str +=pro+ HIY"����˫Ŀ���ǣ�ü�Ҵ��飬�������޲�Ϊ֮�Ķ���\n"NOR;
                if (per <= 32 && (per > 31))
                        str +=pro+ HIY"���ھٶ���������ˮ�����̷��飬������������Ŀ�⡣\n"NOR;
                if (per <= 31 && (per > 30))
                        str +=pro+ HIY"����˫�۹⻪Ө��͸���������ǵĹ�â��\n"NOR;
                if (per <= 30 && (per > 29))
                        str +=pro+ HIY"����Ӣ���������������Ρ�\n"NOR;
                if (per <= 29 && (per > 28))
                        str +=pro+ MAG"����Ŀ�Ƶ��ᣬ�ߴ�ͦ���������Ķ���\n"NOR;
                if (per <= 28 && (per > 27))
                        str +=pro+ MAG"�����������£�����˹�ģ���ֹ�ʶȡ�\n"NOR;
                if (per <= 27 && (per > 26))
                        str +=pro+ MAG"���ý�ü��Ŀ��Ӣ�˲������Ǳ�����\n"NOR;
                if (per <= 26 && (per > 25))
                        str +=pro+ MAG"��������Ũ�ף����۱��ǣ��������ݣ������㵹��\n"NOR;
                if (per <= 25 && (per > 24))
                        str +=pro+ MAG"����ü��˫�����������ǣ�Ӣͦ���ڡ�\n"NOR;
                if (per <= 24 && (per > 23))
                        str +=pro+ CYN"���û���������׳��������Ӣ�˲�����\n"NOR;
                if (per <= 23 && (per > 22))
                        str +=pro+ CYN"���÷�ɫ��𪣬�촽ī����˹������\n"NOR;
                if (per <= 22 && (per > 21))
                        str +=pro+ CYN"����Ũü���ۣ��ߴ�ͦ�Σ�����������\n"NOR;
                if (per <= 21 && (per > 20))
                        str +=pro+ CYN"���ñ�ֱ�ڷ��������������Գ������Ը�\n"NOR;
                if (per <= 20 && (per > 19))
                        str +=pro+ CYN"����üĿ���㣬�����󷽣�һ���˲š�\n"NOR;
                if (per <= 19 && (per > 18))
                        str +=pro+ YEL"������Բ���������ڷ����Ǹ񲻷���\n"NOR;
                if (per <= 18 && (per > 17))
                        str +=pro+ YEL"������òƽƽ�������������ʲôӡ��\n"NOR;
                if (per <= 17 && (per > 16))
                        str +=pro+ YEL"���ð����Բ���������⣬���ζ��ࡣ\n"NOR;
                if (per <= 16 && (per > 15))
                        str +=pro+ YEL"�����ͷ���룬����һ���Ͳ����øС�\n"NOR;
                if (per <= 15 && (per > 14))
                        str +=pro+ YEL"����������ݣ�����ݹǣ�����Ҫ�����Ρ�\n"NOR;
                if (per <= 14 && (per > 13))
                        str +=pro+ RED"���÷�ͷ�������Բ��ģ��ֽŶ̴֣����˷�Ц��\n"NOR;
                if (per <= 13 && (per > 12))
                        str +=pro+ RED"������ü���ۣ�������ߣ�������״��\n"NOR;
                if (per <= 12 && (per > 11))
                        str +=pro+ RED"���������Ƥ��ͷ���������˲����ٿ��ڶ��ۡ�\n"NOR;
                if (per <= 11 && (per > 10))
                        str +=pro+ RED"�����������죬������ף�����ޱȡ�\n"NOR;
                if (per <= 10)
                        str +=pro+ RED"����ü����б����ͷѢ�ţ�����������\n"NOR;
        }
        else
        {
            if ((string) obj->query("gender") == "Ů��")
            {
                if (per >=40) 
                        str +=pro+ HIW"�������������ܣ������ƻã��Ѳ����Ƿ�������\n"NOR;
                if (per <= 39 && (per > 38))
                        str +=pro+ HIG"�����������ɣ���մһ˿�̳���\n"NOR;
                if (per <= 38 && (per > 37))
                        str +=pro+ HIG"���ڲ�����ϼ���������񣬻����������ӡ�\n"NOR;
                if (per <= 37 && (per > 36))
                        str +=pro+ HIG"�����������������Ż���ɽ�����˼�֮���ס�\n"NOR;
                if (per <= 36 && (per > 35))
                        str +=pro+ HIG"���ڷ����۰ף�Ӥ��С�ڣ�üĿ���飬�·�̫�����١�\n"NOR;
                if (per <= 35 && (per > 34))
                        str +=pro+ HIG"�����������ģ����ȷ�����������Σ��۹�֬�ޡ�\n"NOR;
                if (per <= 34 && (per > 33))
                        str +=pro+ HIY"�����������ã�ü��ī���������Ұ꣬Ŀ���ﲨ��\n"NOR;
                if (per <= 33 && (per > 32))
                        str +=pro+ HIY"���ڷ�����ü�����溬�����������ݣ�ת�ζ��顣\n"NOR;
                if (per <= 32 && (per > 31))
                        str +=pro+ HIY"����üĿ�续������ʤѩ�����ν�����߻���\n"NOR;
                if (per <= 31 && (per > 30))
                        str +=pro+ HIY"���ڽ����������������£�����ܳ������㡣��\n"NOR;
                if (per <= 30 && (per > 29))
                        str +=pro+ HIY"�����о���毻���ˮ���ж����������磬��̬��ǧ��\n"NOR;
                if (per <= 29 && (per > 28))
                        str +=pro+ MAG"���ý�С���磬��������������������ˡ�\n"NOR;
                if (per <= 28 && (per > 27))
                        str +=pro+ MAG"����Ѽ��������������ü���ڷ����٣��������֡�\n"NOR;
                if (per <= 27 && (per > 26))
                        str +=pro+ MAG"��������ϸ����������������Ķ��ˣ�������ɡ�\n"NOR;
                if (per <= 26 && (per > 25))
                        str +=pro+ MAG"���÷���ϸ������欶��ˣ�����һ�����������ѡ�\n";
                if (per <= 25 && (per > 24))
                        str +=pro+ MAG"���÷��۰���������ҩ���̣����￴����\n"NOR;
                if (per <= 24 && (per > 23))
                        str +=pro+ CYN"������������Ŀ����ˮ��ǧ�����ġ�\n"NOR;
                if (per <= 23 && (per > 22))
                        str +=pro+ CYN"�����������ģ�����Ө͸��������˼��\n"NOR;
                if (per <= 22 && (per > 21))
                        str +=pro+ CYN"������Ц��Ȼ����Լ���ˡ�\n"NOR;
                if (per <= 21 && (per > 20))
                        str +=pro+ CYN"�������滨��¶������������\n"NOR;
                if (per <= 20 && (per > 19))
                        str +=pro+ CYN"���÷��˳������������ˡ�\n"NOR;
                if (per <= 19 && (per > 18))
                        str +=pro+ YEL"���ü���΢�ᣬ�ŵ��������¿��ˡ�\n"NOR;
                if (per <= 18 && (per > 17))
                        str +=pro+ YEL"�����䲻���£���Ҳ�׾�����Щ����֮����\n"NOR;
                if (per <= 17 && (per > 16))
                        str +=pro+ YEL"���������С�������޹⣬��������\n"NOR;
                if (per <= 16 && (per > 15))
                        str +=pro+ YEL"���øɻƿ��ݣ���ɫ���ƣ�����Ů��ζ��\n"NOR;
                if (per <= 15 && (per > 14))
                        str +=pro+ YEL"�����������Ƥɫ�ֺڣ���ª������\n"NOR;
                if (per <= 14 && (per > 13))
                        str +=pro+ RED"����һ�����������һ����û�øС�\n"NOR;
                if (per <= 13 && (per > 12))
                        str +=pro+ RED"������С�綹��üëϡ�裬�����צ������������\n"NOR;
                if (per <= 12 && (per > 11))
                        str +=pro+ RED"���ð���ü�������ۣ���Ƥ�Ʒ�������һ�������¡�\n"NOR;
                if (per <= 11 && (per > 10))
                        str +=pro+ RED"�������б�ۣ���ɫ�Ұܣ�ֱ����һ�㡣\n"NOR;
				if (per <=10) 
                        str +=pro+ RED"���ó������Σ�״��ҹ�棬Ů�˳������������������硣\n"NOR;
            }
            else
            {
                if (living(obj))
		{
                if (!obj->query_temp("owner"))
                   str += pro+"��һֻδ��ѱ�����������۹������ǽ��ĺ͵��⡣\n";
                else
                   str += pro+"��һֻ��"+obj->query_temp("ownername")+"ѱ����������һ������ѱ�����ӡ�\n";
		}
            }
        }

        // If we both has family, check if we have any relations.
        if( obj!=me
        &&      mapp(fam = obj->query("family"))
        &&      environment(me) == environment(obj)
        &&      mapp(my_fam = me->query("family")) 
        &&      fam["family_name"] == my_fam["family_name"] ) {
        
                if( fam["generation"]==my_fam["generation"] ) {
                        if( (string)obj->query("gender") == "����" ||
                                (string)obj->query("gender") == "����")
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                        else
                                str += sprintf( pro + "�����%s%s��\n",
                                        my_fam["master_id"] == fam["master_id"] ? "": "ͬ��",
                                        my_fam["enter_time"] > fam["enter_time"] ? "ʦ��": "ʦ��");
                } else if( fam["generation"] < my_fam["generation"] ) {
                        if( my_fam["master_id"] == obj->query("id") )
                                str += pro + "�����ʦ����\n";
                        else if( my_fam["generation"] - fam["generation"] > 1 )
                                str += pro + "�����ͬ�ų�����\n";
                        else if( fam["enter_time"] < my_fam["enter_time"] )
                                str += pro + "�����ʦ����\n";
                        else
                                str += pro + "�����ʦ�塣\n";
                } else {
                        if( fam["generation"] - my_fam["generation"] > 1 )
                                str += pro + "�����ͬ������\n";
                        else if( fam["master_id"] == me->query("id") )
                                str += pro + "����ĵ��ӡ�\n";
                        else
                                str += pro + "�����ʦֶ��\n";
                }
        }

////////////////////////////////////////////////////////////////////////////////////////////////////
        if (me->is_jiebai_of(obj))
        {
              if( obj->query("gender")=="Ů��" )
              {
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s�������㡣\n", pro);
                    else
                        str += sprintf("%s����Ľ������ӡ�\n", pro);
              }
              else{
                    if (obj->query("mud_age") > me->query("mud_age"))
                        str += sprintf("%s����Ľ����ֳ���\n", pro);
                    else
                        str += sprintf("%s�������ܡ�\n", pro);
              }
        }
////////////////////////////////////////////////////////////////////////////add jiebai list by lisser
        if( obj->is_spouse_of(me) )
                str += pro + "�����" + me->query("spouse/title") + "��\n";
                
        if( obj->query("max_qi") )
                str += pro + COMBAT_D->eff_status_msg((int)obj->query("eff_qi") * 100 / (int)obj->query("max_qi")) + "\n";

        inv = all_inventory(obj);
        if( sizeof(inv) ) {
                inv = map_array(inv, "inventory_look", this_object(), obj->is_corpse()? 0 : 1 );
                inv -= ({ 0 });
                if( sizeof(inv) )
                        str += sprintf( obj->is_corpse() ? "%s�������У�\n%s\n" : "%s���ϴ�����\n%s\n",
                                pro, implode(inv, "\n") );
        }

        message("vision", str, me);

        if( obj!=me && !obj->is_spouse_of(me) 
        &&      living(obj)
        &&      random(-(int)obj->query("shen")) > (int)me->query("int") * 10 ) {
                write( obj->name() + "ͻȻת��ͷ������һ�ۡ�\n");
              if ((int)me->query("combat_exp") > 100000) COMBAT_D->auto_fight(obj, me, "berserk"); 
        }

        return 1;
}

string inventory_look(object obj, int flag)
{
        string str;

        str = obj->short();
        if( obj->query("embedded") )
                str = HIR "  ��" NOR + str;
        else if( obj->query("equipped") )
                str = HIC "  ��" NOR + str;
        else if( !flag )
                str = "    " + str;
        else
                return 0;

        return str;
}

int look_room_item(object me, string arg)
{
        object env;
        mapping item, exits;

        if( !objectp(env = environment(me)) )
                return notify_fail("����ֻ�л����ɵ�һƬ��ʲôҲû�С�\n");
        if( mapp(item = env->query("item_desc")) && !undefinedp(item[arg]) ) {
                if( stringp(item[arg]) )
                        write(item[arg]);
                else if( functionp(item[arg]) )
                        write((string)(*item[arg])(me));
                        
                return 1;
        }
        if( mapp(exits = env->query("exits")) && !undefinedp(exits[arg]) ) {
                if( objectp(env = find_object(exits[arg])) )
                        look_room(me, env);
                else {
                        call_other(exits[arg], "???");
                        look_room(me, find_object(exits[arg]));
                }
                return 1;
        }
        return notify_fail("��Ҫ��ʲô��\n");
}

int help (object me)
{
        write(@HELP
ָ���ʽ: look [<��Ʒ>|<����>|<����>]
 
���ָ������鿴�����ڵĻ�����ĳ����Ʒ��������Ƿ���
 
HELP
);
        return 1;
}
