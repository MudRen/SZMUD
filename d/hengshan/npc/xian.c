// xian.c
// by firefox

inherit NPC;
inherit F_MASTER;
#include <ansi.h>;
#include "/d/hengshan/npc/roomdb.h"
#include "/d/hengshan/npc/npc_setup.h"
nosave string *chnnumber=({"一","二","三","四","五","六","七","八","九","十","零"});
nosave int mancount=10;

int setnpcstat(object npcob);
int giveexp(int maxman,int i);
int do_fangqi();
string ask_job();
void create()
{
        set_name("定闲师太", ({ "dingxian shitai", "shitai", "dingxian" }) );
        set("gender", "女性");
        set("title", "恒山派第十三代掌门");
        set("class", "bonze");
        set("age", 45);
        set("attitude", "peaceful");
        set("per", 24);
        set("str", 26);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);
        set("combat_exp", 1200000);
        set("shen_type", 1);

		set("no_get", 1);
        set_temp("apply/armor", 100);

        set_skill("sword", 130);
        set_skill("force", 130);
        set_skill("parry", 130);
        set_skill("dodge", 130);
        set_skill("hengshan-jian", 130);
        set_skill("lingxu-bu", 130);
        set_skill("ding-force", 130);
        map_skill("force", "ding-force");
        map_skill("sword", "hengshan-jian");
        map_skill("parry", "hengshan-jian");
        map_skill("dodge", "lingxu-bu");

        create_family("恒山派", 13, "掌门");
                set("inquiry", ([
                    "job" : (: ask_job :),
                    "help" : (: ask_job :),
                    "work" : (: ask_job :),
                    "帮助" : (: ask_job :),
					"工作" : (: ask_job :),
                ]));
        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/shaolin/obj/xuan-cloth")->wear();
}
void init()
{
        ::init();
        add_action("do_fangqi","fangqi");
        add_action("do_fangqi","放弃");
}

/*string do_clear()
{
        object ob=this_player();
        ob->delete_temp("jobendtime");
        ob->delete_temp("hengshan/job");
        return "flag delete done.\n";
}*/
string ask_job()
{
        object me,ob,npcob,*inv;
        int i=0,j=0;                    //,j =0;
        me = this_object();
        ob = this_player();

        inv=all_inventory(environment(ob));
        for (i=0;i<sizeof(inv);i++){
                if (inv[i]->query("player_id") == ob->query("id") && living(inv[i]))
                        j++;
        }
        i=0;
        if (sizeof(ob->query("jobendtime") ) && ob->query("jobendtime")<time() )
                ob->set("hengshan/job",2);
        if (sizeof(ob->query("hsnpc") ) == j && ob->query("hsnpc") &&j>0)
                ob->set("hengshan/job",3);
        else if (j>0) ob->set("hengshan/job",4);
        if (ob->query("combat_exp")<150000 || ob->query("max_neili")<1000 )
                return "魔教中人武功非同小可，施主却勿枉自送命！\n";
        switch(ob->query("family/family_name")) {
                case "星宿派":
                case "白驼派":
                case "雪山派":
                case "血刀门":
				case "明教":
                        return "我恒山派纵然一败涂地，尽数覆灭，也不与你等同流合污!\n";
        }
        if (ob->query("shen") <0 )
                return ("施主已堕入魔道，贫尼岂敢劳烦。\n");
        if (ob->query("PKS")>0 && ob->query("PKS")>=((ob->query("MKS")+ob->query("PKS"))/100*10 ) ){
                return ("施主杀人无数，岂是我辈中人所为，贫尼奉劝施主苦海无边回头是岸!\n");
        }
		if (mancount < 1)
		if ( !ob->query("hengshan/job") && me->query("mancount") < 1 )
                return "已有人在援助我派了，施主请回吧！贫尼祷祝施主福体康健，万事如意了。";
        if (!ob->query("hengshan/job")) {
                        i=2+random(3);
                        remove_call_out("make_npc");
                        call_out("make_npc",1,i);
                        ob->set("jobendtime",time()+1200);
                        ob->set("hengshan/job",1);
                        ob->set("hsnpc_num",i+1);
						mancount--;
                        return ("本派收到定静师姐飞鸽传书，我派"+chnnumber[i]+"名弟子在福建泉州遇袭，劳烦施主速到福建\n"+
                                "援助我派弟子。\n");
//                      return ;
        }
        switch(ob ->query("hengshan/job")) {
                case 0:
                case 1:
                        return ("施主可找到我派被困弟子 ？\n");
                        break;
                case 2:
                        ob->delete("jobendtime");
                        ob->delete("hengshan");
						ob->delete("hsnpc_num");
                        ob->delete("hsnpc");
                        ob->delete("block");
                        command("sigh");
						mancount++;
                        return ("施主现时回来，只怕我派弟子已遇难了！\n");
                        break;
                case 3:
                        tell_object(ob,"你感到实战经验增加了！\n");
						mancount++;
                        giveexp(j,j);
                        ob->delete("block");
                        ob->delete("jobendtime");
                        ob->delete("hsnpc");
                        ob->delete("hengshan");
						ob->delete("hsnpc_num");
                        return ("施主救我派弟子于大难，无以为报，贫尼只有朝夕以清香一炷，祷祝施主福体康健，万事如意了。”\n");
                        break;
                case 4:
                        message_vision("$N说道：“多谢施主救我派弟子于大难！”\n",me);
                        return "咦！怎么还少了"+chnnumber[sizeof(ob->query("hsnpc"))-j-1]+"个弟子，烦劳施主再找一找吧！若想放弃(fangqi)贫尼也不敢强求！\n";
                        break;
        }
//      return ;
}
void make_npc(int i)
{
                int j=0,ci=0,kroom,knpc,broom,bnpc;
                object fnpcob,npcob,ob;
                ob=this_player();

                for ( j=0;j<=i; j++ ){
                         kroom=random(sizeof(room));
                         knpc=random(sizeof(npc));
//						 printf("kroomId=[%3d] knpcId=[%d] \n",kroom,knpc);
                         ci=0;
/*   防止同一player出现同名 hengshan npc        */
                         while(ci<sizeof(ob->query("hsnpc"))) {
                                if (ob->query("hsnpc/"+ci) == load_object("/d/hengshan/npc/"+npc[knpc])->query("name") ) {
//                                      write(ob->query_temp("hsnpc/"+ci)+" Vs "+load_object("/d/hengshan/npc/"+npc[knpc])->query("name")+"\n");
                                        ci=0;
                                        knpc=random(sizeof(npc));
                                        continue;
                                }
//                              write("Update Npc Name: "+npc[knpc] +"\n");
                                ci++;
                         }
                         if (j==0) {
                                fnpcob=new ("/d/hengshan/npc/"+npc[knpc]);
                                fnpcob->set("combat_exp",this_player()->query("combat_exp")/3*2);
                                setnpcstat(fnpcob);
                                fnpcob->move("/d/quanzhou/"+room[kroom]);
                                fnpcob->set("bang",1);
//                                environment(fnpcob)->set("no_fight",1);
                                ob->set("hsnpc/"+j,fnpcob->query("name"));
                                bnpc=knpc;
                                broom=kroom;
                 } else
                         {
                                npcob=new ("/d/hengshan/npc/"+npc[knpc]);
                                npcob->set("combat_exp",this_player()->query("combat_exp")/3*2);
                                setnpcstat(npcob);
                                npcob->move("/d/quanzhou/"+room[kroom]);
//                                environment(npcob)->set("no_fight",1);
                                npcob->set("bang",1);
                                ob->set("hsnpc/"+j,npcob->query("name"));
                         }
                         if (j>0 && j<i) {
                                npcob->set("sister_room",room[broom]);
                                npcob->set("sister_name",npc[bnpc]);
                                bnpc=knpc;
                                broom=kroom;
                         }
                         if (j==i) {
                                npcob->set("sister_room",room[broom]);
                                npcob->set("sister_name",npc[bnpc]);
                                fnpcob->set("sister_room",room[kroom]);
                                fnpcob->set("sister_name",npc[knpc]);
                         }
						if(wizardp(this_player())) {
								write("Load room:"+room[kroom]+"   ");
								write("Npc name:"+npc[knpc]+"\n");
						}
                }
}
int setnpcstat(object npcob)
{
        object ob;
        int player_exp;
        ob=this_player();
        player_exp=ob->query("combat_exp");
        set_skills("hengshan",player_exp/3*2,100,npcob);
        set_hp(npcob->query_skill("force",1),npcob);
        npcob->set("player_id",ob->query("id"));
}
int do_fangqi()
{
        object ob=this_player(),*inv;
        int j,i;
/*
        object ob=this_player(),*inv,   fnpcob, hsnpc, *hsnpc_list;
        int j,i,  fnpcob_num;
		fnpcob_num = ob->query_temp("hsnpc_num");
		hsnpc_list = ob->query_temp("hsnpc");
*/
        if (!ob->query("hengshan/job")){
			return 0;
        }
        if (ob->query("hengshan/job")!=4){
			message_vision("$N对$n说道：“唉！施主既肯出手相助，为何不能彻底相助呢！贫尼祷祝施主福体康健。”\n",this_object(),ob);
			mancount++;
			ob->delete("block");
			ob->delete("jobendtime");
			ob->delete("hengshan");
			ob->delete("hsnpc");
			ob->delete("hsnpc_num");
			return 1;
        }

        inv=all_inventory(environment(ob));
        for (i=0;i<sizeof(inv);i++) {
                if(inv[i]->query("player_id") == ob->query("id") )
                        j++;
        }
        giveexp(sizeof(inv),j);
		mancount++;
        message_vision("$N对$n说道：“唉！施主既肯出手相助，为何不能彻底相助呢！贫尼祷祝施主福体康健。”\n",this_object(),ob);
        tell_object(ob,"\n你得到了一些实战经验！\n");
/*
//		测试
		for (i=0; i<fnpcob_num; i++) {
		hsnpc = hsnpc_list[i];
		if (objectp(hsnpc)) {
			message("vision", hsnpc->name(1)+"急急忙忙地离开了.\n", environment(hsnpc), hsnpc);
			destruct(hsnpc);
			}
		}
*/
        ob->delete("block");
        ob->delete("jobendtime");
        ob->delete("hengshan");
        ob->delete("hsnpc");
		ob->delete("hsnpc_num");
        return 1;
}
int giveexp(int maxman,int i)
{
        object ob=this_player(),*inv;
        int maxexp=500,givepotential,j;
        inv=all_inventory(environment(ob));
        for ( j=0;j<sizeof(inv);j++) {
                if (inv[j]->query("player_id") == ob->query("id") ){
                        message_vision("$N对着$n躬身作了个揖。说道：“此次蒙难幸得施主舍命相助，小尼定会铭记于心，小尼告辞！”\n",inv[j],ob);
                        destruct(inv[j]);
                }
        }
        maxexp=maxexp+maxexp/maxman*i+random(50+(ob->query("jobendtime")-time())/10/maxman*i);
        givepotential=ob->query("max_potential")/3*2/maxman*i+random(ob->query("max_potential")/100*5);
        if (maxman == i ) {
                maxexp=maxexp+random(50+(ob->query("jobendtime")-time())/10);
                givepotential=ob->query("max_potential")/3+random(ob->query("max_potential")/100*10);
        }
        ob->add("combat_exp", maxexp);
        ob->add("potential", givepotential);
        if ( ob->query("potential") > ob->query("max_potential") )
                ob->set("potential", ob->query("max_potential") );

        return 1;
}
#include "/d/hengshan/npc/npc_setup.c"
