//ansnpc.c
//Code by Scatter

#include <ansi.h>
#define SAVE_NPC "/family_job/savenpc"

inherit NPC;

string ask_move();

void create()
{
		set_name("门派弟子", ({ "menpai dizi", "menpai", "dizi"  }));

        set("gender", "男性");
        set("age", 30);
        set("long", "看上去像是一位高手。\n");

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
		command("say 你说的好像行不通耶再试试看");
		return 1;
	}


	intExp = random(200) + 600;
	ob->add("potential", ob->query("max_potential"));
	ob->add("combat_exp", intExp);
	
	strFNameP = ob->query("family/family_name");
	switch(strFNameP)
	{
	case "武当派":
		{
			strMenpaiP = "wd";
			break;
		}
	case "少林派":
		{
			strMenpaiP = "sl";
			break;
		}
	case "丐帮":
		{
			strMenpaiP = "gb";
			break;
		}
	case "星宿派":
		{
			strMenpaiP = "xx";
			break;
		}
	case "峨嵋派":
		{
			strMenpaiP = "em";
			break;
		}
	case "大理段家":
		{
			strMenpaiP = "dl";
			break;
		}
	case "古墓派":
		{
			strMenpaiP = "gm";
			break;
		}
	case "白驼山":
		{
			strMenpaiP = "bt";
			break;
		}
	case "华山派":
		{
			strMenpaiP = "hs";
			break;
		}
	case "雪山派":
		{
			strMenpaiP = "xs";
			break;
		}
	case "桃花岛":
		{
			strMenpaiP = "th";
			break;
		}
	case "全真教":
		{
			strMenpaiP = "qz";
			break;
		}
	case "昆仑派":
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
	log_file("/job/question_job", ob->query("name") + "(" + ob->query("id") + ") 成功做了一次新版门派工作(智慧版)  "+ctime(time())+"\n");

	tell_object(ob, CYN"门派弟子说道：对呀我怎么没想到呢\n");
	tell_object(ob, CYN"门派弟子抱拳团团一拜，讨好地说道：在下对各位的景仰之情，有如滔滔江水连绵不绝。\n");

	remove_action("do_answer", "ans");
	remove_call_out("do_time_up");
	destruct(this_object());
	return 1;
}



void do_time_up()
{
    object user;
    string uid = query( "aid" );
    if ( uid )
    user = find_player( uid );
    // for now, do not decrease whole menpai gxd
    if ( user )
        //user->add( "menpai/gxd", -20 );
	tell_object(this_player(), CYN"门派弟子说道：真的很抱歉时间到了看来我还是找别人好了\n");
	remove_action("do_answer", "ans");
	destruct(this_object());
	return;
}
