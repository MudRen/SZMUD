//// Code of ShenZhou
//Modify by snso
// /d/huanghe/npc/bangzhu.h
// by aln  18/ 8 / 2k

void init()
{
        object ob = this_player();

        ::init();

        if( !is_fighting()
        &&  interactive(ob) ) {
                remove_call_out("checking");
                call_out("checking", 1, ob);
        }

        add_action("do_check", "exert");
        add_action("do_check", "yun");
        add_action("do_xue", "xue");
}

void checking(object ob)
{
        object me = this_object();

        if( !living(me) || is_fighting() ) return;

        if( environment() != environment(ob) ) return;

        if( ob->query_temp("bangs/fam") == query("fam") ) {
                message_vision("$N������$n��ͷ˵�������ͣ����ְ﷢��������ĺô���\n", me, ob);
                return;
        }

        if( !random(2) )
                message_vision("$N˫�ֱ�ȭ��ţ��ţ����˵�����������������ѵ�û���κα�ʾ��\n", me);
        else    message_vision("$N˵���������Ͽ����" + query("fam") + "������\n", me);
}

int do_check(string arg)
{
        string what, who;

        if( !arg ) return notify_fail("");

        if( arg != "play" ) {
                 if( sscanf(arg, "%s %s", what, who) != 2 )
                          return notify_fail("");

                 if( what != "play" )
                          return notify_fail("");
        }

        call_other(BANGSKILLS + "play2", "exert", this_player(), this_player());
        return 1;
}

int ask_join()
{
        object ob = this_player(), obj, situ = this_object();
        string ob_fam;
        object sf_d;
	string myfam,mypos,msg,*msg_a,nowmsg,sfn;
	int lastscore,score,i;
        

        myfam = (string)query("fam");
        if( (string)ob->query_temp("bangs/fam") == myfam ) {
                say(name() + "��ŭ����" + RANK_D->query_rude(ob) + "�����ҿ���������Ц������\n");
                return 1;
        }


        if( time() < (int)ob->query("bangs/jointime") + 600 ) {
                say(name() + "��ŭ����" + RANK_D->query_rude(ob) + "������˷����޳����������ڽ���������\n");
                return 1;
        }

        message_vision("$N���ص�����һ��$n�ļ�򣬺ȵ��������ģ��ӽ��Ժ���ֵ�������ͬ����\n", this_object(), ob);

        ob->set_temp("apply/short",
                ({ HIR + myfam + "���� "NOR + ob->query("name")+"("+capitalize(ob->query("id"))+")" }));
        ob->delete_temp("bangs");
        ob->delete("bangs");
        ob->set_temp("bangs/fam", myfam);
        ob->set("bangs/jointime", time());

        if( obj = present("bang ling", ob) )
                destruct(obj);

        obj = new(BANGLING);
        obj->set("owner", ob->query("id"));
        obj->set("fam", myfam);
        obj->set("combat_exp", query("combat_exp"));
        obj->set("long",
"����" + myfam + "�İ��������š�" + ob->query("name") + "����\n");
        obj->move(ob);
        message_vision("$N��һ" + obj->query("unit") + obj->name() + "�Ӹ�$n��\n", this_object(), ob);
        
        score = ob->query("clbscore");
	if ( stringp (mypos = ob->query("clbpos")) )
	{	if ( score < 200000 )
		{	ob->delete("clbpos");
                        if( strlen ( msg = read_file(POSFILE)) > 0 )
			{   
                	msg_a = explode(msg,"\n");
                	msg="";
                	nowmsg = ob->query("id")+"("+ mypos + ")";
                        for(i=0; i< sizeof(msg_a); i++)
                        	if(msg_a[i] != nowmsg) msg += ( msg_a[i]+"\n");
                        write_file(POSFILE,msg,1);
                        }
                        switch(mypos)
                        {
                        case "������" : write_file("/d/forest/sifang/sifang1_file","",1);sfn="1";break;
                        case "ʨ����" : write_file("/d/forest/sifang/sifang2_file","",1);sfn="2";break;
        		case "������" : write_file("/d/forest/sifang/sifang3_file","",1);sfn="3";break;
        		case "ӥѸ��" : write_file("/d/forest/sifang/sifang4_file","",1);sfn="4";break;
        		case "������" : write_file("/d/forest/sifang/sifang5_file","",1);sfn="5";break;
        		}
        		if ( sf_d = find_object(SF_DIR + sfn) )
        			destruct(sf_d);
        		
                        message_vision(HIM"��Ϊ����̫�$N��"+mypos+"����һְ������\n"NOR,ob);
                        command("chat ��Ϊ�����������Σ�"+ ob->name()+ "�ĳ��ְ�"+ mypos +"����ְλ��������\n");
		}
		else
		{	ob->set_temp("bangs/pos", mypos);
        		ob->set_temp("bangs/pos_time", uptime());
        		ob->set_temp("bangs/pos_score", score);
                        
        		ob->set_temp("apply/short",
   			({ HIR + myfam + mypos + "���� "NOR + ob->query("name")+"("+capitalize(ob->query("id"))+")" }));
   			message_vision("$N��"+mypos+"����һְ�ָ��ˡ�\n",ob);
   		}
	}

        log_file("BangJoin", sprintf("%s��%sʱ����%s\n", ob->query("name"), ctime(time()), myfam));
        return 1;
}

// duty 2 teach skills

string ask_skills()
{
        object ling, me = this_player();
        int amount;

        if( is_fighting() )
                return RANK_D->query_rude(me) + "Ϲ����û������æ�ţ���";

        if( (string)me->query_temp("bangs/fam") != (string)query("fam") )
                return RANK_D->query_rude(me) + "Ī����������Ұ�����ܰɡ�";
        
        if( (amount = (int)me->query("clbscore")) < 10 )
                return RANK_D->query_rude(me) + "�ټӰѾ��������Ż�ָ����һ�£�";

        if( amount > 100 ) {
                me->set_temp("bangs/skills_asked", 100);
               
                me->add("clbscore",-100);
        } 
        else {
                me->set_temp("bangs/skills_asked", amount);
                me->add("clbscore",-amount);
        }

        tell_object(me, "����룺�书��Ӣ�����֡�\n");
        return "�ðɡ�";
}

int do_xue(string arg)
{
        object me = this_player();
        string *sname;
        int i, amount, level, mylvl;

        if( !(amount = (int)me->query_temp("bangs/skills_asked")) ) {
                write("�㻹û�������ͬ���ء�\n");
                return 1;
        }

        if( is_fighting() ) {
                say(name() + "��ŭ����" + RANK_D->query_rude(me) + "Ϲ����û������æ�ţ���");
                return 1;
        }

        if( !arg ) {
                sname = keys(query_skills());
                write("\n" + name() + "��ѧ���ļ��ܣ�\n\n");
                for(i = 0; i < sizeof(sname); i++)
                        write(to_chinese(sname[i]) + " (" + sname[i] + ")" + "\n");
                return 1;
        }

        if( (level = (int)query_skill(arg, 1)) < 1 ) {
                say(name() + "ҡ��ҡͷ��������ûѧ����\n");
                return 1;
        }

        mylvl = (int)me->query_skill(arg, 1);
        if( level < mylvl ) {
                say(name() + "��ŭ����" + RANK_D->query_rude(me) + "��Ȼ���������ˡ�\n");
                return 1;
        }

        if( mylvl > 120 ) {
                say(name() + "ҡ��ҡͷ�������ȥ��������ʽ��ʦ���ܼ������" + to_chinese(arg) + "��\n");
                return 1;
        }

        if( (int)me->query("jing")*2 < (int)me->query("max_jing") ) { 
                write("����Ъ����ɡ�\n");
                return 1;
        }
        me->add("jing", -(int)me->query("max_jing")/2 + 10);
        me->improve_skill(arg, amount * me->query("int") / 6); 
        me->delete_temp("bangs/skills_asked");

        message_vision("$N��$n����йء�" + to_chinese(arg) + "�������ʡ�\n", me, this_object());
        tell_object(me, "�����˰�����ָ�����ԡ�" + to_chinese(arg) + "���ƺ���Щ�ĵá�\n");
        return 1;
}

// duty 3 died to give bangyin
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

void die()
{
        object ob, corpse, killer;

        if( !living(this_object()) ) revive(1);
        clear_condition();

        if( objectp(killer = query_temp("last_damage_from")) ) {
                ob = new(BANGYIN);
                ob->set("long", query("fam") + ob->query("name") + "��\n");
                ob->move(environment());
                message_vision(HIR"\nͻȻ��$N�´��е���һ" + ob->query("unit") + ob->name() + "��\n"NOR, this_object());
                set_temp("my_killer", killer->query("id"));
                ob->set("my_killer",  killer->query("id"));
                ob->set("combat_exp", query("combat_exp"));
        }
    
        COMBAT_D->announce(this_object(), "dead");
        if( objectp(corpse = CHAR_D->make_corpse(this_object(), killer)) )
                corpse->move(environment());
        remove_all_killer();
        all_inventory(environment())->remove_killer(this_object());

        dismiss_team();
        destruct(this_object());
}
