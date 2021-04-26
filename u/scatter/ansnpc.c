//ansnpc.c
//Code by Scatter

#include <ansi.h>
#define SAVE_NPC "/family_job/savenpc"

inherit NPC;

string ask_move();

void create()
{
		set_name("���ɵ���", ({ "menpai dizi", "menpai", "dizi"  }));

        set("gender", "����");
        set("age", 30);
        set("long", "����ȥ����һλ���֡�\n");

        set("combat_exp", 1000);
        set("shen_type", -1);

        set("attitude", "heroism");
        set("c_time", 1);
        setup();

		carry_object("/clone/armor/tiejia")->wear();
		call_out("do_time_up", 60);
}

void init()
{
	object me=this_player();
	if(query("aid")==me->query("id"))
	{
		add_action("do_answer", "ans");		
	}
}


int do_answer(string arg)
{

	object ob = this_player(), me;
    string strMenpaiP, strFNameP, fname, pdata, ropen;
    string fnamep, fdata;
    int cvalue, intExp;
	me = this_object();


	if(!arg)
	{
		return 0;
	}

	if(arg != query("correctans"))
	{
		command("say ��˵�ĺ����в�ͨҮ�����Կ�");
		return 1;
	}


	intExp = random(200) + 600;
	ob->add("potential", ob->query("max_potential"));
	ob->add("combat_exp", intExp);
	
	strFNameP = ob->query("family/family_name");
	switch(strFNameP)
	{
	case "�䵱��":
		{
			strMenpaiP = "wd";
			break;
		}
	case "������":
		{
			strMenpaiP = "sl";
			break;
		}
	case "ؤ��":
		{
			strMenpaiP = "gb";
			break;
		}
	case "������":
		{
			strMenpaiP = "xx";
			break;
		}
	case "������":
		{
			strMenpaiP = "em";
			break;
		}
	case "����μ�":
		{
			strMenpaiP = "dl";
			break;
		}
	case "��Ĺ��":
		{
			strMenpaiP = "gm";
			break;
		}
	case "����ɽ":
		{
			strMenpaiP = "bt";
			break;
		}
	case "��ɽ��":
		{
			strMenpaiP = "hs";
			break;
		}
	case "ѩɽ��":
		{
			strMenpaiP = "xs";
			break;
		}
	case "�һ���":
		{
			strMenpaiP = "th";
			break;
		}
	case "ȫ���":
		{
			strMenpaiP = "qz";
			break;
		}
	case "������":
		{
			strMenpaiP = "kl";
			break;
		}
	default:
		{
			strMenpaiP = "error";
		}
	}


	//SETTING UP CONNECTION STRING

	fname = "family_job/"+strMenpaiP;
	ropen = SAVE_NPC->do_load(fname);
	cvalue = atoi(ropen);
	cvalue = cvalue + 20;
	
	
	pdata = "" + cvalue;
	fdata = "family_job/"+strMenpaiP;
	SAVE_NPC->do_save(fdata, pdata);


	fnamep = "family_job/password/"+strMenpaiP;
	ropen = SAVE_NPC->do_load(fnamep);
	
	if(ropen != "NA")
	{
		if(ob->query("family_job/password") != ropen)
		{
			ob->delete("menpai/gxd");
			ob->set("family_job/password", ropen);
		}
	}

	ob->add("menpai/gxd", 20);
	log_file("/job/question_job", ob->query("name") + "(" + ob->query("id") + ") �ɹ�����һ���°����ɹ���(�ǻ۰�)  "+ctime(time())+"\n");

	tell_object(ob, CYN"���ɵ���˵������ѽ����ôû�뵽��\n");
	tell_object(ob, CYN"���ɵ��ӱ�ȭ����һ�ݣ��ֺõ�˵�������¶Ը�λ�ľ���֮�飬�������Ͻ�ˮ���಻����\n");

	remove_action("do_answer", "ans");
	remove_call_out("do_time_up");
	destruct(this_object());
	return 1;
}



void do_time_up()
{
		tell_object(this_player(), CYN"���ɵ���˵������ĺܱ�Ǹʱ�䵽�˿����һ����ұ��˺���\n");
		remove_action("do_answer", "ans");
		destruct(this_object());
		return;
}
