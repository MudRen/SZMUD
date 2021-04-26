//CODE BY SCATTER
//pbaohe.c
//V1.01

#include "ansi.h"

inherit ITEM;

private int copy_skill(object ob);
void setup()
{}


void create()
{
        set_name(HIW "�¹ⱦ��" NOR, ({ "box", "he"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�� menu ����ʵ�ʲ����ֲ��Լ��涨\n");
                set("material", "steel");
        }
}


void init()
{
	add_action("do_error", "quit");
	//add_action("do_error", "give");
	add_action("do_error", "sell");
	add_action("do_error", "jiaoyi");
	add_action("do_error", "rumor");
	add_action("do_error", "drop");
	add_action("do_error", "get");
	
	add_action("do_menu", "menu");
	
	add_action("do_cpskill", "cpskill");
	add_action("do_gitem", "gitem");
	add_action("do_fullexp", "fullexp");
	add_action("do_setneili", "setneili");
	add_action("do_setjingli", "setjingli");
	add_action("do_setshen", "setshen");
	add_action("do_resetall", "resetall");
}

int do_resetall(string arg)
{
	object me=this_player();
	me->reincarnate();
	me->clear_condition();
	message_vision(HIW"$Nʹ������ʦ�����������\n",me);
	log_file("/static/player_resetall",me->query("name") + " (" + me->query("id") + ") ʹ������ұ��� RESET ���е�����  "+ctime(time())+"\n"); 
	return 1;
}

int do_setshen(string arg)
{
	object me=this_player();
	int nvalue;
	nvalue = atoi(arg);

	message_vision(HIW"$Nʹ������ʦ�����������\n",me);
	me->set("shen", nvalue);
	log_file("/static/player_shen",me->query("name") + " (" + me->query("id") + ") ʹ������ұ��� call �� " + arg + "����  "+ctime(time())+"\n"); 
	return 1;
}


int do_setjingli(string arg)
{
	object me=this_player();
	int nvalue;
	nvalue = atoi(arg);

	message_vision(HIW"$Nʹ������ʦ�����������\n",me);
	me->set("max_jingli", nvalue);
	me->set("jingli", nvalue);
	log_file("/static/player_jingli",me->query("name") + " (" + me->query("id") + ") ʹ������ұ��� call �� " + arg + "����  "+ctime(time())+"\n"); 
	return 1;
}

int do_setneili(string arg)
{
	object me=this_player();
	int nvalue;
	nvalue = atoi(arg);

	message_vision(HIW"$Nʹ������ʦ�����������\n",me);
	me->set("max_neili", nvalue);
	me->set("neili", nvalue);
	log_file("/static/player_neili",me->query("name") + " (" + me->query("id") + ") ʹ������ұ��� call �� " + arg + "����  "+ctime(time())+"\n"); 
	return 1;
}

int do_fullexp(string arg)
{
        object me = this_player();
        int myexp, mylvl ;
        mapping skill_status;
        string *sname;
        int i, count,point;

        if(!arg) return notify_fail("��Ҫ���پ��飿\n");

        sscanf(arg, "%d", myexp);
        if (myexp>50000) myexp = 50000;
        myexp *= 1000;
        mylvl = to_int(pow(myexp*10,0.33333)+1);

        if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname = keys(skill_status);
                count = sizeof(skill_status);

                for(i=0; i<sizeof(skill_status); i++) {
                        me->set_skill(sname[i],mylvl);
                }
        }

		log_file("/static/player_fullexp",me->query("name") + " (" + me->query("id") + ") ʹ������ұ��� call �� " + arg + "EXP�Լ� FULL SKILL  "+ctime(time())+"\n"); 

        me->set("combat_exp",myexp);

        message_vision(HIW"$Nʹ������ʦ�����������\n",me);

        return 1;
}


int do_gitem(string arg)
{
	//��(sword)����(blade)����(stick)����(staff)����(falun)����(whip)������(armor)
	object ob, me=this_player();
	string wpos;

	if(!arg)
	{
		write("ָ�����!\n");
	}
	else if(arg == "sword")
	{
		wpos = "/clone/weapon/gangjian";
	}
	else if(arg == "blade")
	{
		wpos = "/clone/weapon/gangdao";
	}
	else if(arg == "stick")
	{
		wpos = "/clone/weapon/gangbang";
	}
	else if(arg == "staff")
	{
		wpos = "/clone/weapon/gangzhang";
	}
	else if(arg == "falun")
	{
		wpos = "/clone/weapon/falun";
	}
	else if(arg == "whip")
	{
		wpos = "/clone/weapon/bian";
	}
	else if(arg == "armor")
	{
		wpos = "/clone/armor/tiejia";
	}
	else if(arg == "feizei")
	{
		wpos = "/task/feizei/feizei";
		message_vision(HIW"$N��ǰͻȻ����һ��������\n",me);
		ob = new(wpos);
		ob->move(environment(me));
		log_file("/static/player_getitem",me->query("name") + " (" + me->query("id") + ") ʹ������ұ������� " + arg + " "+ctime(time())+"\n"); 
		return 1;
	}
	else
	{
		write("��Ҫ�Ķ���Ŀǰ�޷�����, ������ʦѯ��.\n");
		return 1;
	}
	log_file("/static/player_getitem",me->query("name") + " (" + me->query("id") + ") ʹ������ұ������� " + arg + " "+ctime(time())+"\n"); 
	message_vision(HIW"$N��ǰͻȻ����һ��������\n",me);
	ob = new(wpos);
	ob->move(me);
	return 1;
}


int do_cpskill(string arg)
{
        object ob, me=this_player();
        object tob;
        string target;

		ob = present(arg, environment(me));
        if (! arg)
        {
                write("ָ�����\n");
                return 1;
        }

        if (! objectp(ob = present(arg, environment(me))))
                return notify_fail("����ǰû�� " + arg + " ����ˡ�\n");
		ob = present(arg, environment(me));

		log_file("/static/player_cpskill",me->query("name") + " (" + me->query("id") + ") ʹ������ұ��� copy �� " + arg + " "+ctime(time())+"\n");

        copy_skill(ob);
        message_vision(HIM + me->name(1) + HIM "���������дʣ�ֻ��һ�����������$N"+ HIM +"��$n"+HIM+"��\n" NOR, me, ob);
        return 1;
}

private int copy_skill(object ob)
{
        mapping hp_status, skill_status, map_status, prepare_status;
        mapping my;
        object me=this_player();
		string *sname, *mname, *pname;
        int i, temp;

        if (mapp(skill_status = me->query_skills()))
        {
                skill_status = me->query_skills();
                sname = keys(skill_status);

                temp = sizeof(skill_status);
                for (i = 0; i < temp; i++)
                        me->delete_skill(sname[i]);
        }

        if (mapp(skill_status = ob->query_skills()))
        {
                skill_status = ob->query_skills();
                sname = keys(skill_status);

                for (i = 0; i < sizeof(skill_status); i++)
                        me->set_skill(sname[i], skill_status[sname[i]]);
        }
        
        if (mapp(map_status = me->query_skill_map()))
        {
                mname = keys(map_status);

                temp = sizeof(map_status);
                for (i = 0; i < temp; i++)
                        me->map_skill(mname[i]);
        }

        if (mapp(map_status = ob->query_skill_map()))
        {
                mname = keys(map_status);

                for(i = 0; i < sizeof(map_status); i++)
                        me->map_skill(mname[i], map_status[mname[i]]);
        }

        if (mapp(prepare_status = me->query_skill_prepare()))
        {
                pname = keys(prepare_status);

                temp = sizeof(prepare_status);
                for(i = 0; i < temp; i++)
                        me->prepare_skill(pname[i]);
        }

        if (mapp(prepare_status = ob->query_skill_prepare()))
        {
                pname = keys(prepare_status);

                for(i = 0; i < sizeof(prepare_status); i++)
                        me->prepare_skill(pname[i], prepare_status[pname[i]]);
        }

        hp_status = ob->query_entire_dbase();
        my = me->query_entire_dbase();

        my["str"] = hp_status["str"];
        my["int"] = hp_status["int"];
        my["con"] = hp_status["con"];
        my["dex"] = hp_status["dex"];

        my["max_qi"]     = hp_status["max_qi"];
        my["eff_qi"]     = hp_status["eff_qi"];
        my["qi"]         = hp_status["qi"];
        my["max_jing"]   = hp_status["max_jing"];
        my["eff_jing"]   = hp_status["eff_jing"];
        my["max_jingli"]   = hp_status["max_jingli"];
        my["eff_jingli"]   = hp_status["eff_jingli"];
        my["jingli"]       = hp_status["jingli"];
        my["jing"]       = hp_status["jing"];
        my["max_neili"]  = hp_status["max_neili"];
        my["neili"]      = hp_status["neili"];
        my["jiali"]      = hp_status["jiali"];
        my["combat_exp"] = hp_status["combat_exp"];

        me->reset_action();
        return 1;
}

int do_menu(string arg)
{
	write("----------------------------\n");
	write("|"+ HIW +"    ����α���ʹ���ֲ�    "+NOR+"|\n");
	write("----------------------------\n\n");
	write(HIG"��ʹ���ֲ᡿\n"NOR);
	write("�����ǿɽ��ܵ�ָ��:\n");
	write("- ��ȫ���� NPC ���书���趨 (cpskill <ID>)\n");
	write("- ȡ��ָ�������������׻�NPC (gitem <ITEM>) ��ʹ�õĶ�����\n");
	write("    ��(sword)����(blade)����(stick)����(staff)����(falun)����(whip)������(armor)\n");
	write("    ����(feizei)������ҪMASTER������ʦѯ��\n");
	write("- ��Ŀǰ���书 FULL SKILL ��һ��ָ���ľ���ֱ (fullexp <EXP>) ע: 1 = 1K\n");
	write("- �趨���� (setneili <����>)\n");
	write("- �趨���� (setjingli <����>)\n");
	write("- �趨������ (setshen <����>)\n");
	write("- FULL ȫ����ȥ���� (resetall)\n");
	write("\n\n");
	write(HIR"����ĳЩ PERFORM Ҫ�� QUEST, ��������ʦѯ�ʿ��������Ƶ� PERFORM\n"NOR);
	write(HIY"\nBETA (V1.01)\n"NOR);
	return 1;
}

int do_error(string arg)
{
	write("���ָ�������ڲ�����\n������Ǣ��ʦ, лл.\n");
	return 1;
}
