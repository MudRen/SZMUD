//CODE BY SCATTER

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
        string fname, pdata, menpaid, gxd;

                sscanf(arg, "%s %s", menpaid, gxd);

        fname = "family_job/"+menpaid;
        pdata = gxd;
        SAVE_NPC->do_save(fname, pdata);
        write("DATA SAVE\n");
        return 1;
}

int do_see(string arg)
{

        string fname, ropen;
        fname = "family_job/" + arg;
        ropen = SAVE_NPC->do_load(fname);
        write(ropen+"\n");
        return 1;
}
