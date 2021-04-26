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


#ifndef NPCDATA 
#define NPCDATA "/data/npc/" 
#endif 
#define SAVE_NPC NPCDATA + "savenpc"

inherit NPC;
inherit F_SAVE;

string query_save_file()
{
return SAVE_NPC;
}


void do_save(string fname, string pdata);
string do_load(string fname);

void create()
{
        set_name("���ϴ������", ({ "savenpc" }));
        set("gender", "����");
        set("age", 19);

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void do_save(string fname, string pdata)
{
        object me=this_object();

        restore_object("/data/npc/savenpc");
        me->set(fname, pdata);
        save();
restore_object("/data/npc/savenpc");
        return;
}

string do_load(string fname)
{
        object me=this_object();
        string strOutPut;

        restore_object("/data/npc/savenpc");
        if(!me->query(fname))
        {
                strOutPut = "NA";
        }

        else
        {
                strOutPut = me->query(fname);
        }

        //write(strOutPut+"\nOUTPUT\n");
        return strOutPut;
}

        
