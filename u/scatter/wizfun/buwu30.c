//buwu.c �����������

#include <ansi.h>
#include <weapon.h>
inherit SWORD;


void create()
{
        set_name("����ɰ��������� (V 3.0)",({"buwu"}));

        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                    set("unit","ֻ");
                set("long","���ǲ���ɰ���������, ���Զ��������µ�ָ�� (V, 3.0)\n kick buwu \n da buwu \n smash buwu \n sorry buwu \n roll buwu \n sit buwu \n stand buwu \n left buwu \n right buwu\n sing buwu \n���д�Ź����!!\n");
                set("value", 0);
                set("material", "steel");
        }
                set("wposition", "/u/scatter/wizfun/buwu30.c"); 
        init_sword(1);
        setup();
}


void init() 
{
        add_action("do_wield", "wield");
        add_action("do_kick", "kick");
        add_action("do_da", "da");
        add_action("do_smash", "smash");
        add_action("do_sorry", "sorry");
        add_action("do_roll", "roll");
        add_action("do_sit", "sit");
        add_action("do_stand", "stand");
        add_action("do_left", "left");
        add_action("do_right", "right");
        add_action("do_sing", "sing");

}

int do_sing (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIG"*****�� ������˹(Felix) �Ṳ*****\n$N���˰�����ı���\n���䳪���ˡ����޵İ���������� -- ������ȫ\n��·���Ĺ���վ��ֱ, ��������, ���ڵ���\n"NOR, me);
                return 1;
        }

        return 0;
}



int do_right (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIC"$N˵��: ����ת!\n����˵��: YES SIR!  (����תȥ��)\n"NOR, me);
                return 1;
        }

        return 0;
}


int do_left (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIY"$N˵��: ����ת!\n����˵��: YES SIR!  (����תȥ��)\n"NOR, me);
                return 1;
        }

        return 0;
}


int do_stand (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIW"$N˵��: վ����!\nֻ�������䱻�ŵ�վ������\n"NOR, me);
                return 1;
        }

        return 0;
}

int do_sit (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIW"$N˵��: ����!\nֻ�����������������\n"NOR, me);
                return 1;
        }

        return 0;
}


int do_roll (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIW"$N˵��: �Ҳ��������. ���䵹�ڵ��ϣ���һ����ľ����ֱ����һ���űߣ���µµ�ı���˳�ȥ��.\nһ�߹�һ��˵, �����ҵĴ�.\n"NOR, me);
                return 1;
        }

        return 0;
}


int do_wield (string arg)
{
        if(arg = "buwu")
        {
                write("���ǳ�������, ��������\n");
                return 1;
        }

        return 0;
}


int do_kick (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIW"$Nʹ����Ӱ�ſ��ٵ�����һ�����˹�ȥ.\n"NOR, me);
                return 1;
        }

        return 0;
}

int do_da (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIC"$Nʹ����ɳ��һ�ƽ�����ѹ���ڵ���.\n"NOR, me);
                return 1;
        }

        return 0;
}



int do_smash (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIG"$N�ǳ�һ������ڲ���ͷ������ϰ���.\n"NOR, me);
                return 1;
        }

        return 0;
}



int do_sorry (string arg)
{
        object me = this_player();
        if(arg = "buwu")
        {
                message_vision(HIY"$N���˲���һ��, ֻ������һֱ˵��: �Բ���, �Ҵ���, ���Ұ�.\n"NOR, me);
                return 1;
        }

        return 0;
}

