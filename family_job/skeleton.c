// Code by Scatter
// skeleton.c


#define SAVE_NPC "/family_job/savenpc"
inherit NPC;

void create()
{
        set_name("骷髅", ({ "skeleton" }));
        set("gender", "男性");
        set("age", 25);
        set("long", "全身都是白骨,　看起来令人毛骨悚然。\n");

        setup();
}

void init()
{
        object me=this_player(), ob=this_object();
        ob->reincarnate();
        
        command("kill " + query_temp("fjob/target"));
        command("follow " + query_temp("fjob/target"));
}

void die()
{ 
        object ob = this_player(), me=this_object();
    string strMenpaiP, strFNameP, fname, pdata, ropen;
    string fnamep, fdata;
    int killnum;
        
        if( !living(this_object()) ) revive(1);

        fname = "fjob/mp/killnum";
        ropen = SAVE_NPC->do_load(fname);

        killnum = atoi(ropen);
        killnum = killnum + 1;

        pdata = "" + killnum;

        SAVE_NPC->do_save(fname, pdata);
        ::die();
}



