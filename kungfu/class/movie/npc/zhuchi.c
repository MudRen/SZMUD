#include <ansi.h>
inherit NPC;


void create()
{
        set_name("������", ({ "zhuchi","zhu chi" }));
        set("title","�н�����");
        set("long", "һ������΢Ц���������������ˡ�\n");
        set("gender", "����");
        set("age", 25);
        set("max_jing", 200);
        set("max_qi", 200);
        
        set("combat_exp", 10000);
        set("shen_type", 1);
        
        set("inquiry", ([
                "�н�����" : "�н��������ӰƬ���ŵ���;���С�\n",
                "��Ʊ" : "��Ʊ�����ݲ�Ʊ�з��еġ������õ���Ʊ��Ʒ��Ž�Ƥ���ﱣ�ܺá�\n",
                "Ƥ��" : "Ƥ�ҿ��Ե����ݲ�Ʊ��ȥ��ȡ����ȡ�Ժ�Ϳ�����Զ�������ϡ�\n",
        ]));
        
        setup();
}




