// CODE BY SCATTER
// NEW WUDANG

inherit ROOM;
#include <room.h>
#include <ansi.h>
#include "numbers.h"

//Anti-ROBOT CODE PROVIDE BY YEER
string look_shiliang();
string make_msg(mapping num, string question);
void make_question(object user);
void get_question();
void no_answer(object user);
int do_anser(string arg);
int do_kill(string arg);

mapping colors = ([
        "��" : RED,
        "��" : WHT,
        "��" : GRN,
        "��" : BLU,
        "��" : CYN,
        "��" : MAG,
        "��" : YEL,
        ]);



void create()
{
        int npclvl, npcexp, npcshen;
        object ob;
        set("short", "ʯ��");

        set("long", @LONG
���������ϵ�ʯ��ͽ��������ͱ��ϣ���������Ƕ��ǧ������֮�䡣
ʯ���Ͻ����죬���پ����������һ�Ϊһ�壬ʹ����Ϊ������񹦡�ʯ���
���ұ߳�һ����ʯ�������������塣��ͷ����С��¯����ȥ��
�������ð������Σ����ȥ���㣬�׳Ƶ���ʯ��Ϊ����ͷ�㡱��
LONG

        );

        set("outdoors", "wudang");



        set("exits", ([

                "northdown" : __DIR__"nanyan",

				"eastdown" : __DIR__"shidian",

        ]));



        set("cost", 6);





                                npclvl = 450;

                npcexp = 15000000;

                npcshen = -1;





                ob=new("/kungfu/class/wudang/job_xx.c");



                ob->set("max_qi", 4000);

                ob->set("max_neili", 50000);

                ob->set("max_jingli", 50000);

                ob->set("max_jing", 50000);

                ob->set("nickname", "���β鿴Ա");



                ob->set("str", 40);

                ob->set("con", 40);

                ob->set("int", 20);

                ob->set("dex", 40);

        

//                ob->set("wudang/id", me->query("id"));

                ob->set("combat_exp", npcexp);

                ob->set("shen", npcshen);

                                ob->set_skill("force", npclvl);

                ob->set_skill("dodge", npclvl);

                ob->set_skill("parry", npclvl);

                ob->set_skill("sword", npclvl);

                ob->set_skill("cuff", npclvl);

                ob->set_skill("strike", npclvl);

                ob->set_skill("claw", npclvl);

                ob->set_skill("finger", npclvl);

                ob->set_skill("blade", npclvl);



                ob->set_skill("huoyan-dao", npclvl);

                ob->set_skill("jingang-chu", npclvl);

                ob->set_skill("liuhe-qiang", npclvl);

                ob->set_skill("longxiang-banruo", npclvl);

                ob->set_skill("mingwang-jian", npclvl);

                ob->set_skill("riyue-lun", npclvl);

                ob->set_skill("shenkongxing", npclvl);

                ob->set_skill("xue-dao", npclvl);



                ob->map_skill("blade", "xue-dao"); 

                ob->map_skill("force", "longxiang-banruo"); 

                ob->map_skill("parry", "huoyan-dao"); 

                ob->map_skill("strike", "huoyan-dao"); 

                ob->map_skill("dodge", "shenkongxing"); 



                ob->prepare_skill("strike", "huoyan-dao"); 



                ob->reincarnate();

                                ob->move("/d/wudang/shidian");



        setup();

}





void init()

{

        add_action("do_mianbi","���");
        add_action("do_mianbi","mianbi");
		add_action("do_answer", "answer");

}









string make_msg(mapping num, string question)

{

        int q, q_size, i1 = random(2), i2 = random(2), i3 = random(2), i4 = random(2), i5 = random(2);

        int *i_num = ({i1, i2, i3, i4, i5});

        string msg = "���㿴ͼ�ش����⣺\n����";

        while (sizeof(question)<16) {

                q_size = sizeof(question);

                q = random(8);

                question = question[0..q*2+1]+"��"+question[(q+1)*2..q_size];

        }

        for (int i =0; i < 8; i++) {

                for (int j = 1; j <= 5; j++ )

                {

                        msg += sprintf("%s%s%s", num["color"+j], numbers[atoi(num["num"+j])][i], (i_num[j-1])?"��":"");

                }

                msg += NOR + question[i*2..(i*2+1)] + "\n����";

        }

        return msg;

}



void get_question()

{

        object user = this_player(1);

        make_question(user);

        return;

}



void make_question(object user)

{

        int answer, i, j, k, q, p, z, color_num = sizeof(colors);

        string question, *color_name, *color, c_name, colorx;

        mapping num = ([]);

        if(stringp(user->query("robot_answer"))) {

                tell_object(user, "�㻹�ǻش�ղŵ�������˵�ɡ�\n");

                return;

        }

        switch (5)

        {

        case 0: i = random(10), j = random(10), k = random(10), p = random(5), q = random(5), z = random(2);

                question = "������������";

                while(j == i) j = random(10);

                while(k == i || k == j) k = random(10);

                while(q == p) q = random(5);

                num["num" + (p + 1)] = sprintf("%d", (z == 0 ? j : k));

                num["num" + (q + 1)] = sprintf("%d", (z == 1 ? j : k));

                for (int o = 1 ;o <= 5 ;o++ )

                {

                        if(o != (p+1) && o != (q+1)) num["num" + o] = "" + i;

                        num["color" + o] = NOR;

                }

                question = make_msg(num, question);

                answer = i;

                this_object()->set("num", num);

                break;

        case 1: i = random(10), j = random(10), p = random(5), q = random(5);

                question = "������������";

                while(j == i) j = random(10);

                while(q == p) q = random(5);

                num["num" + (p + 1)] = "" + j;

                num["num" + (q + 1)] = "" + j;

                for (int o = 1 ;o <= 5 ;o++ )

                {

                        if(o != (p+1) && o != (q+1)) num["num" + o] = "" + i;

                        num["color" + o] = NOR;

                }

                question = make_msg(num, question);

                this_object()->set("num", num);

                answer = i;

                break;

        case 2: i = random(10), j = random(10), p = random(5);

                question = "������������";

                while(j == i) j = random(10);

                num["num" + (p + 1)] = "" + j;

                for (int o = 1 ;o <= 5 ;o++ )

                {

                        if(o != (p+1)) num["num" + o] = "" + i;

                        num["color" + o] = NOR;

                }

                question = make_msg(num, question);

                answer = i;

                break;

        case 3: i = random(10), j = random(10), p = random(5);

                question = "�������ٵ�����";

                while(j == i) j = random(10);

                num["num" + (p + 1)] = "" + j;

                for (int o = 1 ;o <= 5 ;o++ )

                {

                        if(o != (p+1)) num["num" + o] = "" + i;

                        num["color" + o] = NOR;

                }

                question = make_msg(num, question);

                answer = j;

                break;

        case 4: i = random(10), j = random(10), p = random(5);

                question = "�������ٵ�����";

                while(j == i) j = random(10);

                num["num" + (p + 1)] = "" + j;

                for (int o = 1 ;o <= 5 ;o++ )

                {

                        if(o != (p+1)) num["num" + o] = "" + i;

                        num["color" + o] = NOR;

                }

                question = make_msg(num, question);

                answer = j;

                break;

        case 5: i = random(10), p = random(5);

                color_name = keys(colors);

                color = values(colors);

                c_name = color_name[random(color_num)];

                num["num" + (p + 1)] = "" + i;

                num["color" + (p + 1)] = colors[c_name];

                question = c_name + "ɫ�����֡�";

                for (int o = 1 ;o <=5 ;o++ )

                {

                        colorx = color[random(color_num)];

                        while(colorx == colors[c_name]) colorx = color[random(color_num)];

                        if(o != (p+1)) {

                                num["num" + o] = "" + random(10);

                                num["color" + o] = colorx;

                        }

                }

                question = make_msg(num, question);

                answer = i;

                break;

        }

        user->set("robot_answer", "" + answer);

        tell_object(user, question + "\n" + "���������ӻش�������⣬�ش�����ʹ��ָ��answer\n");

        remove_call_out("no_answer");

        call_out("no_answer", 180, user);

        return;

}



int do_answer(string arg)

{

        object user = this_player();

        if(!stringp(user->query("robot_answer"))) return 0;

        if(!arg || arg!= user->query("robot_answer")) {

                user->add("be_robot", 1);

                tell_object(user, "�ش�������Ѿ�����" + chinese_number(user->query("be_robot")) + "���ˡ�\n");

                if(user->query("be_robot")>=3) {

                        tell_object(user, "����Ǹ�����Ĺ������벻Ҫ��ʹ�û����ˡ�\n(��ĵȴ�ʱ����" + user->query("wudang/mianbirobot") + "�롣)\n");

                                                user->delete("be_robot");

                                                user->delete("robot_answer");

                                                user->add("wudang/mianbirobot", 600);

                                                user->set_temp("wudang/failquestion", user->query("wudang/mianbirobot"));

                                                

                                                remove_call_out("fail_question_count"); 

                                                call_out("fail_question_count", 1); 



                        return 1;

                }

                tell_object(user, "�������³��⡣\n");

                user->delete("robot_answer");

                make_question(user);

                return 1;

        }

        tell_object(user, "�ش���ȷ������Լ��������ˡ�\n");

                tell_object(user, "��õ��˵�ѧ�ķ��Ľ�����\n");

        user->move(user->query("left_place"));

        remove_call_out("no_answer");

                user->improve_skill("taoism", 200);

                remove_call_out("start_lingwu");

                call_out("start_lingwu", 1);





        user->delete("left_place");

        user->delete("robot_answer");

        user->delete("be_robot");

        return 1;

}



void no_answer(object user)

{

        tell_object(user, "����Ǹ�����Ĺ������벻Ҫ��ʹ�û����ˡ�\n(��ĵȴ�ʱ����" + user->query("wudang/mianbirobot") + "�롣)\n");

                user->delete("be_robot");

                user->delete("robot_answer");

                user->add("wudang/mianbirobot", 600);

                user->set_temp("wudang/failquestion", user->query("wudang/mianbirobot"));

                remove_call_out("fail_question_count"); 

                call_out("fail_question_count", 1);

        return;

}









void fail_question_count()

{

        object me = this_player();
      if(!me) return;
        if(me->query_temp("wudang/failquestion") < 1)

        {

                me->delete_temp("wudang/failquestion");

                return;

        }

        

        me->add_temp("wudang/failquestion", -1);

        remove_call_out("fail_question_count"); 

        call_out("fail_question_count", 1);

        return;

}











int do_mianbi()
{



        object me, mengzhu, room, ob;
        int shen, ep, gain, shengain, pots, mylvl, myexp, myshen, npclvl, npcexp, npcshen, comexp, i;
		string appmsg;
        me = this_player();
        shen = me->query("shen");
        ep = me->query("combat_exp");

		if (me->query_temp("wudang/failquestion"))
			return notify_fail("�㻹��Ҫ�ٵȴ�һ��ʱ�䣡\n(��ĵȴ�ʱ����" + me->query_temp("wudang/failquestion") + "�롣)\n");

        if( me->query_skill_mapped("force") != "taiji-shengong" )
		{
			write("\n���䵱��̫���񹦻�û��������������Ѫ��ת��\n");
			me->unconcious();
			return 1;
		}

		
		if (me->query_temp("wudang/mianbib"))
			return notify_fail("�������꣬�㲻��ͷ����\n�ȵ�����һ�ΰɣ�\n");

        if (me->is_busy() || me->query_temp("pending/exercising") || me->query_temp("exit_blocked"))
			return notify_fail("��������æ���ء�\n");

        if (me->query("jing") < 200 || me->query("jingli") < 200)
			return notify_fail("����÷��겻�������Ծ۾��붨��\n");


		if (random(100) < 50)
        {
			me->start_busy(1);

			write("\n��ӭ���������˲���ϵͳ (V 1.0)\n������ϵͳ�ǣ�Ϊ������Ϸ��ø���Ȥ����������ζ��\n\n���������...\n\n");



			//              remove_call_out("get_question"); 
            
            //              call_out("get_question", 1); 
            
                            get_question();
                
         }
        
		else

		{

			write("������...\n");
			me->start_busy(2);

			call_out("start_lingwu", 1);

		}

                return 1;

}







void start_lingwu()

{

        object me, mengzhu, room, ob;

        int shen, ep, gain, shengain, pots, mylvl, myexp, myshen, npclvl, npcexp, npcshen, comexp, i;

                string appmsg;

        me = this_player();

        shen = me->query("shen");

        ep = me->query("combat_exp");

        


if (me->query("combat_exp")>4500000) message_vision("$N�����ʯ��������˼�������ƺ��Ѵ���ǰ��\n", me);
if (me->query("combat_exp")<4500001) message_vision("$N�����ʯ��������˼�����ã���������\n", me);



                if (me->query("neili") > me->query("max_neili"))

                {

                        me->set("neili", me->query("max_neili"));

                }





        me->start_busy(8);

        me->set("jing",1);

        me->add("jingli", -200);

                me->add("neili", -1000);



        if (shen > 100000 && shen > ep)

                {

                        gain = (200 + random((shen - ep) * 1000 / ep)) * 2;







                        if (me->query("family/family_name") != "�䵱��" && me->query("combat_exp")>6400000 )

                                gain = gain*2/3;

                        if (me->query("family/family_name") != "�䵱��" && me->query("combat_exp")< 6400000 )

                                gain = gain/4;


if (me->query("combat_exp")>6400000) me->add("combat_exp", gain/6);

if (me->query("combat_exp")>4500000) me->add("combat_exp", gain/2);

if (me->query("combat_exp")<4500001) me->add("combat_exp", gain);



            shengain = shen - ((shen - ep) / 2);    

            me->set("shen", shengain);

                        //pots = (gain * me->query_skill("taoism") / 80 + random(gain*me->query_skill("taoism")/60)) / 2;

                                                pots = (gain * 7 / 10) - random(60) + (me->query_skill("taoism") / 4);



                        if (me->query("family/family_name") == "�䵱��")

if (me->query("combat_exp")>4500000) me->add("potential", pots/2);

if (me->query("combat_exp")<4500001) me->add("potential", pots);




                if ( me->query("potential") > me->query("max_potential") )

                {

                        me->set("potential", me->query("max_potential"));

                }







                log_file("/job/wudang_mianbi",me->query("name") + " (" + me->query("id") + ") ��ڻ�� " + gain + " �㾭��� "+ pots + " ��ǳ�ܣ����ܹ����� " + (shen - ep) / 2 +" ������"+ctime(time())+"\n");







    }

        

                else

                {

                        write("��������������㣬��ȫ�޷����κε�����\n");

                }







                if(random(100) < 40)

                {



                myexp = me->query("combat_exp");

                myshen = me->query("shen");

                comexp = myexp * 10;

                for(i=0;comexp>i*i*i;i++)

                                        mylvl = i + 1;





                npclvl = mylvl * 15 / 16;

                npcexp = myexp + 40000 - (me->query_skill("taoism") * 12);

                npcshen = myshen - myshen - myshen - (myshen / 10);





                ob=new("/kungfu/class/wudang/job_xx.c");



                ob->set("max_qi", me->query("max_qi"));

                ob->set("max_neili", me->query("max_neili"));

                ob->set("max_jingli", me->query("max_jingli"));

                ob->set("max_jing", me->query("max_jing"));

                ob->set("nickname", "Ŀ�꣺"+ me->query("name"));
				ob->set_temp("wd/target", me->query("id"));
				ob->add_temp("wd/btime", 1);
                ob->set("str", 40);

                ob->set("con", 40);

                ob->set("int", 20);

                ob->set("dex", 40);

        

                ob->set("wudang/id", me->query("id"));

                ob->set("combat_exp", npcexp);

                ob->set("shen", npcshen);

                ob->set_skill("force", npclvl);

                ob->set_skill("dodge", npclvl);

                ob->set_skill("parry", npclvl);

                ob->set_skill("sword", npclvl);

                ob->set_skill("cuff", npclvl);

                ob->set_skill("strike", npclvl);

                ob->set_skill("claw", npclvl);

                ob->set_skill("finger", npclvl);

                ob->set_skill("blade", npclvl);



                ob->set_skill("huoyan-dao", npclvl);

                ob->set_skill("jingang-chu", npclvl);

                ob->set_skill("liuhe-qiang", npclvl);

                ob->set_skill("longxiang-banruo", npclvl);

                ob->set_skill("mingwang-jian", npclvl);

                ob->set_skill("riyue-lun", npclvl);

                ob->set_skill("shenkongxing", npclvl);

                ob->set_skill("xue-dao", npclvl);



                ob->map_skill("blade", "xue-dao"); 

                ob->map_skill("force", "longxiang-banruo"); 

                ob->map_skill("parry", "huoyan-dao"); 

                ob->map_skill("strike", "huoyan-dao"); 

                ob->map_skill("dodge", "shenkongxing"); 



                ob->prepare_skill("strike", "huoyan-dao"); 



                ob->reincarnate();

                ob->move("/d/wudang/mshidian");





                switch(random(4))

                                {

                                        case 0:

                                                appmsg = "ͻȻ��";

                                                break;

                                        case 1:

                                                appmsg = "��֪�����ķ��ִ�";

                                                break;

                                        case 2:

                                                appmsg = "��Χ����ֵ���Ϣ�������";

                                                break;

                                        case 3:

                                                appmsg = "����ԼԼ�Ŀ�����";

                                                break;

                                        case 4:

                                                appmsg = "����һ���˴�";

                                                break;

                                }



                                switch(random(7))

                                {

                                case 0:

                                        appmsg = appmsg + "����";

                                        break;

                                case 1:

                                        appmsg = appmsg + "���";

                                        break;

                                case 2:

                                        appmsg = appmsg + "�ұ�";

                                        break;

                                case 3:

                                        appmsg = appmsg + "����";

                                        break;

                                case 4:

                                        appmsg = appmsg + "����";

                                        break;

                                case 5:

                                        appmsg = appmsg + "����";

                                        break;

                                case 6:

                                        appmsg = appmsg + "��֪��ʲô�ط�";

                                        break;

                                case 7:

                                        appmsg = appmsg + "�Ա�";

                                }



                                switch(random(7))

                                {

                                case 0:

                                        appmsg = appmsg + "�ܳ���һ��";

                                        break;

                                case 1:

                                        appmsg = appmsg + "�����һ��";

                                        break;

                                case 2:

                                        appmsg = appmsg + "�߳���һ��";

                                        break;

                                case 3:

                                        appmsg = appmsg + "������һ��";

                                        break;

                                case 4:

                                        appmsg = appmsg + "�ܹ���һ��";

                                        break;

                                case 5:

                                        appmsg = appmsg + "�����һ��";

                                        break;

                                case 6:

                                        appmsg = appmsg + "�߹���һ��";

                                        break;

                                case 7:

                                        appmsg = appmsg + "������һ��";

                                        break;

                                }



                                switch(random(2))

                                {

                                case 0:

                                        appmsg = appmsg + "а�ɵ��ӣ�";

                                        break;

                                case 1:

                                        appmsg = appmsg + "ѩɽ���ӣ�";

                                        break;

                                case 2:

                                        appmsg = appmsg + "���ɵ��ӣ�";

                                        break;

                                }



                        

                                message_vision(HIR"\n" + appmsg + "\n"NOR, me);

								if( me->query_skill_mapped("force") != "taiji-shengong" )
								{
									write("\n������̫����ʱͻȻ�жϣ���������Ѫ��ת��\n");
									me->unconcious();
									return;
								}
								
								ob->kill_ob(me);



                                }







        me->add_temp("wudang/mianbib", 40);

                call_out("mianbi_busy", 1, me);

                return;

}



void mianbi_busy(object me)

{

        if(me->query_temp("wudang/mianbib") > 0)

        {

                me->add_temp("wudang/mianbib", -1);

                call_out("mianbi_busy", 1, me);

        }

        else

        {

                me->delete_temp("wudang/mianbib");

                return;

        }

}