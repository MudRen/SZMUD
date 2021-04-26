 //SAVENPC.C

/*
PASS ON DATA STEP

  1. YOU NEED TO DEFINE THE FOLLOWING LINE BEFORE INHERIT
                
                  #define SAVE_NPC "/family_job/savenpc"

  TO PASS DATA AND SAVE:
  1. TO PASS ON DATA YOU NEED TO CREATE TWO VARIBLES (string pdata, fname;)
     THE FORMAT OF IT IS   
         
           fname = "wizname/filename";
           pdata = "DATA THAT YOU WANT TO BE SAVE";
           
                 SAVE_NPC->do_save(fname, pdata);

  TO LOAD DATA
  2. TO LOAD DATA YOU NEED TO CREATE TWO VARIBLES (string fname, ropen;)
     THE FORMAT OF IT IS

        ropen = SAVE_NPC->do_load(fname);

*/

#define SAVE_NPC "/family_job/savenpc"
inherit NPC;

void create()
{
        set_name("���ϴ������", ({ "savenpc" }));
        set("gender", "����");
        set("age", 19);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_add", "add");
        add_action("do_see", "see");
}


int do_add(string arg)
{
        string fname, pdata;

        fname = "family_job/wd";
        pdata = arg;
        SAVE_NPC->do_save(fname, pdata);
        write("DATA SAVE\n");
        return 1;
}

int do_see(string arg)
{

        string fname, ropen;
        fname = "family_job/wd";
        ropen = SAVE_NPC->do_load(fname);
        write(ropen+"\n");
        return 1;
}
