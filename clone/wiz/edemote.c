// edemote.c emote�༭��
#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD;
void setup()
{}
void create()
{
        set_name(HIC "���鶯�ʱ༭��" NOR, ({"emote editor", "editor"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�ܿ������ֵֹ���������������˵��(help editor)��\n");
                set("value", 1);
                set("no_sell", 1);
        }
        setup();
}

int query_autoload()
{
        return 1;
}

void init()
{
        add_action("do_help", "help");
        if (environment() == this_player())
        {
                add_action("do_edemote", "edemote");
                add_action("do_cpemote", "cpemote");
                add_action("do_rnemote", "rnemote");
        }
}

int do_help(string arg)
{
        if (! arg || ! id(arg))
                return notify_fail("��Ҫ��ʲô������\n");
        write (@HELP
���ڱ��鶯�ʱ༭����˵����

edemote [-d] [-p] verb
���������ڱ༭����ʾ��ɾ��һ�����鶯�ʡ�����verb�Ǳ��鶯�ʣ�
���ʹ����-d������ɾ���ö��ʣ����ʹ����-p��������ʾ�ñ�
�鶯�ʾ���ı���������Ϣ������༭�ı��鶯��ԭ���Ǵ��ڵģ�
���ڱ༭��ʱ�����ֱ������"." �Ա���ԭ�е���Ӧ��Ŀ��

cpemote emote1 emote2
��������Խ���һ�����鶯�ʵ��������Ƴɵڶ������ʵ���������
�Ƶ�ʱ��ԭ�ȱ���û�еڶ������ʵ������������Ժ��һ�����ʵ�
������Ȼ���ڣ�������������������������ͬ�ı��鶯�ʡ�

rnemote emote1 emote2
��������Ըĵ�һ�����鶯�ʵ����֣������������仯��

HELP );
        return 1;
}

int do_edemote(string arg)
{
         return "/cmds/wiz/edemote"->main(this_player(), arg);
}

int do_cpemote(string arg)
{
        return "/cmds/imm/cpemote"->main(this_player(), arg);
}

int do_rnemote(string arg)
{
        return "/cmds/imm/rnemote"->main(this_player(), arg);
}
