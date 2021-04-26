// Code of ShenZhou
// xuan-ku.h for fight and get letter from Xuan
// modified by aln  4 / 98

#include <ansi.h>

string* names = ({
        "chengguan luohan",
        "chengzhi luohan",
        "chengming luohan",
        "chengjing luohan",
        "chengjian luohan",
        "chengxing luohan",
        "chengji luohan",
        "chengmie luohan",
        "chenghe luohan",

        "chengxin luohan",
        "chengyi luohan",
        "chengsi luohan",
        "chengshi luohan",
        "chengzhi luohan",
        "chengxin luohan",
        "chengling luohan",
        "chengyu luohan",
        "chengshang luohan",
});

string ask_me()
{
        mapping fam, my_fam, skl; 
        object fighter, me, room, monk;
        string *sname;
        int i,j, right_time;

        fighter = this_player();

        if( fighter->query("luohan_winner") )
                return RANK_D->query_respect(fighter) + 
                "��Ȼ�����޺����󣬿ɲ�Ҫ�����Ŀ������Ц��";

        right_time = uptime() % 1800;
//        if( right_time < 180 || right_time > 1380
//        ||  ( right_time > 480 && right_time < 1080 ) )
//                return RANK_D->query_respect(fighter) + 
//                "���ò����ɣ������������޺�����ɡ�";

//        if( time() < (int)fighter->query("try_lhz") + 86400 )
//                return RANK_D->query_respect(fighter) +
//                "����ǰ���޺�����ʧ�ܶ��飬�����ڵĹ���һ��Ҳ�������ɡ�";

        skl = fighter->query_skills();
        sname  = keys(skl);  

        for(i=0; i<sizeof(skl); i++) {
                if (skl[sname[i]] < 90)
                return RANK_D->query_respect(fighter) + 
                "���������������ʸ��޺�����";
        }

        me = this_object();
        my_fam  = me->query("family");

        if ( mapp(fam = fighter->query("family")) 
        && fam["family_name"] == "������"
        && fam["generation"] != (my_fam["generation"] + 2))
                return RANK_D->query_respect(fighter) + 
                "���ݲ��ϣ������ʸ��޺�����";

        if ( (int)fighter->query("guilty") > 0 )
                return RANK_D->query_respect(fighter) + 
                "���۷����䣬�������������׼���㴳�޺�����";

        if( base_name(environment()) != "/d/shaolin/luohan5" )
                return RANK_D->query_respect(fighter) + 
                "���ǵ����Ļص��޺�����˵�ɡ�";

        if ( stringp(me->query_temp("busyfor")) ) {
                if( me->query_temp("busyfor") != fighter->query("id") )
                return RANK_D->query_respect(fighter) + 
                "��������������ս�޺��������һ��ʱ�������ɡ�";
                else
                return RANK_D->query_respect(fighter) +
                "���޺����Ѿ�׼��������\n";
        }

        say("\n����˵�����ðɣ������ټ��޺��ó������ڶ����䳡���ϣ����Ժ����������䳡�ϵ��㡣\n");
        message_vision("\n�����ʦ�����뿪��\n\n", fighter);

        for(j=1; j<10; j++) 
        {
                if(!( room = find_object("/d/shaolin/luohan" + j)) )
                room = load_object("/d/shaolin/luohan" + j);

                me->move(room);
                if( !objectp(monk = present(names[j-1], room) )) {
                        me->move("/d/shaolin/luohan5");
                        message_vision("\n�����ʦ���˹�����\n\n", fighter);
                        return "���ǶԲ����޺��������˲��ڣ��޷������޺�����";
                }

/*  Disable by scatter, Request by Buwu
                if( monk->query("jing")*10 < monk->query("max_jing")*8
                ||  monk->query("qi")*10 < monk->query("max_qi")*8
                ||  monk->query("neili")*10 < monk->query("max_neili")*5 ) {
                        me->move("/d/shaolin/luohan5");
                        message_vision("\n�����ʦ���˹�����\n\n", fighter);
                        return "���ǶԲ����޺�������λ�������岻�ʣ��޷������޺�����";
                }
*/

                message("vision", "\n�����ʦ���˹�������" + monk->query("name") + "��������˵�˼��䡣\n", room, monk);
                message("vision", monk->query("name") + "�޺����˵�ͷ���첽���˳�ȥ��\n", room, monk);
                monk->move("/d/shaolin/wuchang2");
        }

        me->move("/d/shaolin/luohan5");
        message_vision("\n�����ʦ���˹�������$N˵�����޺��ó����Ѿ������ڶ����䳡��\n", fighter);
        say("\n�����ֵ���������ȥ��֪���������Ѵ�ʦ�����������м����������޺��������䳡���ϡ�\n");

        message_vision("\n�����ʦ�����뿪��\n\n", fighter);
        me->move("/d/shaolin/wuchang");
        message_vision("\n�����ʦ���˹�����\n\n", me);

        fighter->set_temp("xuanku-ready", 1);
        me->set_temp("busyfor", fighter->query("id"));
        me->set_temp("waiting_time", 0);
        call_out("waiting", 1, fighter);
        return "�ã���Ҷ������ˡ�\n";
}

void waiting(object fighter)
{
        add_temp("waiting_time", 1);
        if( (int)query_temp("waiting_time") >= 300 ) {
                say("�����ʦ˵�����������յ��޺�������ûϷ�ˣ����ǻ�ȥ�գ�\n\n");
                call_out("do_back", 0);
                return;
        }

        if( !fighter ) {
                say("����˵�����������������ˣ����ǻ�ȥ�գ�\n\n");
                call_out("do_back", 0);
                return;
        }

        if( !fighter->query_temp("xuannan-ready") ) {
                if( !random(10) )
                say("\n����˵����" + "�����ó��ϻ�û�м��Ϻã��ٵ�һ�����\n");
                call_out("waiting", 1, fighter);
                return;
        }

        if( environment(fighter) != environment() ) {
                if( !random(10) )
                say( "\n����˵�������޺�������˻�û׼���ã��ٵ�һ����ɡ�\n");
                call_out("waiting", 1, fighter);
                return;
        }

        fighter->delete_temp("xuanku-ready");
        fighter->delete_temp("xuannan-ready");
        fighter->set("try_lhz", time());

        call_out("preparing", 1, fighter);
}

void preparing(object fighter)
{
        object monk1, monk, room1, room;

        if( !fighter ) {
                say("�����ʦ˵�����������յ��޺�������ûϷ�ˣ����ǻ�ȥ�գ�\n\n");
                call_out("do_back", 0);
                return;
        }

        room = environment();
        if( !objectp(monk = present("xuannan dashi", room)) ) {
                say("�����ʦ˵�����������յ��޺�������ûϷ�ˣ����ǻ�ȥ�գ�\n\n");
                call_out("do_back", 0);
                return;
        }

        say("�����ʦ�����Ѵ�ʦ���˵�ͷ�����Ѵ�ʦ���˵�ͷ��\n");

        say( "����˵��������ɵ��ˣ��粻���ֳ���Ħ�޺������뼴���뿪�˴���\n");

        if(!( room1 = find_object("/d/shaolin/wuchang2")) )
        room1 = load_object("/d/shaolin/wuchang2");
        monk1 = present("mu ren", room1);
        monk1->move("/d/shaolin/houdian");

        if(!( room1 = find_object("/d/shaolin/wuchang1")) )
        room1 = load_object("/d/shaolin/wuchang1");
        monk1 = present("mu ren", room1);
        monk1->move("/d/shaolin/houdian");

        if( objectp(monk1 = present("daojue chanshi", room)) ) {
                message("vision", "�����ʦ��������ʦ��������˵�˼��䡣\n", room, monk1 );
                message("vision", monk1->query("name") + "��ʦ���˵�ͷ���첽�����뿪��\n", room);
                monk1->move("/d/shaolin/houdian");
        }

        message("vision", HIY "\n�����ʦ�������������޺������Χ��\n" NOR, room);
        message("vision", HIY "\n���Ѵ�ʦ�������������޺������Χ��\n\n" NOR, room);

        command("chat " + fighter->query("title") + fighter->query("name") + 
                "�ڽ���" + NATURE_D->game_time() + "��ս����ʮ���޺�����");

        message("vision", "\nֻ����������ɳɳ�ĽŲ���������ʮ��λ�޺��Ǹ���������ɱ��\n"
                "����ֿ�ȭ�����ֱֳ�����������Χ����������ס��ͨ·��\n\n", room);
        room->set("store", room->query("exits"));
        room->delete("exits");

        say( "�����ֵ���׼�����޺����󼴿̷�����\n\n");
        call_out("fighting", 3, fighter, 0);
        remove_call_out("do_back");
        call_out("do_back", 50);
        return;
}

void fighting(object fighter, int count)
{
        object monk, room1, room;

        if( !fighter ) {
                 say("����ҡ��ҡͷ��˵�����벻�� ... ����\n\n");
                 command("sigh");
                 remove_call_out("do_back");
                 call_out("do_back", 1);
                 return;
        }

        room = environment();
        if( environment(fighter) != room ) {
                 say("����ҡ��ҡͷ��˵�����벻�� ... ����\n\n");
                 command("sigh");
                 remove_call_out("do_back");
                 call_out("do_back", 1);
                 return;
        }

        if( !living(fighter) || fighter->query("qi") <= 1
        ||  fighter->query_temp("apply/armor") >= 100 ) {
                 say("����ҡ��ҡͷ��˵�����벻�� ... ����\n\n");
                 command("comfort " + fighter->query("id"));     
                 remove_call_out("do_back");
                 call_out("do_back", 1);
                 return;
        }

        if( (count % 2) == 0 )
        message("vision", "\n�޺������ٵ���ת�ţ�һ���������ս���\n" NOR, room);

        if( count <= 8 ) {
                 if(!( room1 = find_object("/d/shaolin/wuchang2")) )
                 room1 = load_object("/d/shaolin/wuchang2");

                 if( !objectp(monk = present(names[count], room1)) ) {
                         command("sorry " + fighter->query("id"));
                         command("say ��һ���������岻�ʣ��޺����󲻵ò���ɢ��");
                         remove_call_out("do_back");
                         call_out("do_back", 1);
                         return;
                 }
        } else if( count <= 17 ) {
                 if(!( room1 = find_object("/d/shaolin/wuchang1")) )
                 room1 = load_object("/d/shaolin/wuchang1");

                 if( !objectp(monk = present(names[count], room1)) ) {
                         command("sorry " + fighter->query("id"));
                         command("say ��һ���������岻�ʣ��޺����󲻵ò���ɢ��");
                         remove_call_out("do_back");
                         call_out("do_back", 1);
                         return;
                 }
        } else {
                 call_out("do_recruit", 1, fighter);
                 return;
        }

        monk->move(room);
        if( fighter->query("family/family_name") != "������" ) {
                 monk->add_temp("apply/attack", 20);
                 monk->add_temp("apply/damage", 20);
                 fighter->add_temp("apply/defense", -20);
               COMBAT_D->do_attack(monk, fighter, monk->query_temp("weapon"));
                 monk->add_temp("apply/attack", -20);
                 monk->add_temp("apply/damage", -20);
                 fighter->add_temp("apply/defense", 20);
        } else 
               COMBAT_D->do_attack(monk, fighter, monk->query_temp("weapon"));

        monk->move(room1);
        
        count++;
        if( (count % 2) > 0 )  fighting(fighter, count);
        else call_out("fighting", 1, fighter, count);
}

void do_recruit(object fighter)
{
        mapping ft_fam, my_fam;

        if( (int)fighter->query("combat_exp") < 300000 )
        fighter->add("combat_exp", 20000000 / (100000 + (int)fighter->query("combat_exp")) * 100);
        fighter->delete("try_lhz");
        fighter->set("luohan_winner", 1);

        if (!(ft_fam = fighter->query("family")) || ft_fam["family_name"] != "������")
        {
                command("bow");
                say("����˵����" + RANK_D->query_respect(fighter) + "�˷����󣬵��Ա������д������棬�ٳ߸�ͷ������һ�������ľʹ˱����\n");
                remove_call_out("do_back");
                call_out("do_back", 5);
        }
        else
        {
                say("\n����˵������ϲ�㴳����ʮ���޺����� �����д˵Ƚܳ����ӣ���ʱ�ص�Ϊ���ַ�һ��ʣ�\n");
                remove_call_out("do_back");
                call_out("do_back", 20);
        }
}

void do_back()
{
        object monk, room, room1, room2, room3;
        int i;

        room = environment();
        message("vision", "\n�����ʦ���˻��֣� �޺��ó������漴����뿪���䳡��\n", room );
        if( !mapp(room->query("exits")) && mapp(room->query("store")) )
        room->set("exits", room->query("store"));

        if(!( room1 = find_object("/d/shaolin/houdian")) )
        room1 = load_object("/d/shaolin/houdian");

        if( objectp(monk = present("daojue chanshi", room1)) )
        monk->move("/d/shaolin/wuchang");

        if( objectp(monk = present("mu ren", room1)) )
        monk->move("/d/shaolin/wuchang1");

        if( objectp(monk = present("mu ren", room1)) )
        monk->move("/d/shaolin/wuchang2");

        for(i = 1; i < 10; i++) {
                if( !( room2 = find_object("/d/shaolin/wuchang2")) )
                room2 = load_object("/d/shaolin/wuchang2");

                if( objectp(monk = present(names[i-1], room2)) )
                monk->move("/d/shaolin/luohan" + i);
        }

        if( objectp(monk = present("xuannan dashi", room)) ) {
                message("vision", "\n���Ѵ�ʦҲ���˻��֣� �����ó������漴Ҳ�뿪���䳡��\n", room );
                monk->delete_temp("busyfor");
                monk->move("/d/shaolin/banruo5");

                for(i = 10; i < 19; i++) {
                if( !( room3 = find_object("/d/shaolin/wuchang1")) )
                room3 = load_object("/d/shaolin/wuchang1");
     
                if( objectp(monk = present(names[i-1], room3)) )
                monk->move("/d/shaolin/banruo" + (i - 9));
                }
        }

        delete_temp("busyfor");
        move("/d/shaolin/luohan5");
}

void attempt_apprentice(object ob)
{
        object me; 
        mapping ob_fam, my_fam;
        string name, new_name;

        me = this_object();
        my_fam  = me->query("family");

        name = ob->query("name");

        if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "������")
        {
                command("say " + RANK_D->query_respect(ob) + "�뱾��������������֪�˻��Ӻ�̸��");
                return;
        }

        if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "������") 
        {
                command("say " + RANK_D->query_respect(ob) + "���׼ҵ��ӣ�����������ѧ�ա�");
                return;
        }

        if ( ob_fam["generation"] < my_fam["generation"] )
        {
                command("say " + RANK_D->query_respect(ob) + "��ƶɮ����ҵ� !");
                return;
        }

        if ( (ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "��") 
        ||   (ob_fam["generation"] >=  my_fam["generation"]      && name[0..1] == "��") )
        {
                command("say " + ob_fam["master_name"] + "��ͽ����ô�ܵ���������ˣ������� !");
                command("recruit " + ob->query("id"));
        }

        if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
        {
                if ( ob->query("luohan_winner") )
                {       
                        command("say ���Ĵ���֮�꣬�ֵ�һ����֮�ţ����ǿ�ϲ�ɺ� !");

                        name = ob->query("name");
                        new_name = "��" + name[2..3];
                        ob->set("name", new_name);
        
                        command("say �ӽ��Ժ���ķ�������" + new_name + "����ϲ������Ϊ�����ɳ��ֱ��޺�֮һ !");
                        command("recruit " + ob->query("id"));
                }
                else
                {
                        command("say " + RANK_D->query_respect(ob) + "����û�д���ʮ���޺����󣬲���Խ����ʦ��");
                        return;
                }
        }

        return;
}
