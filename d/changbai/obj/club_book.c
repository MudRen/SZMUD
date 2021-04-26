// Code of ShenZhou
// /d/changbai/npc/club_book.c  ����ͼ��
// by aln  2 / 98

inherit ITEM;

void create()
{
        set_name("����ͼ��", ({ "club book", "book" }));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ����װ�飬������������Ļ��˲�����������ơ�\n");
                set("value", 200);
                set("material", "paper");
                set("skill", ([
                        "name": "club",        // name of the skill
                        "exp_required": 1000,   // minimum combat experience required
                        "jing_cost":    30,     // jing cost every time study this
                        "difficulty":   10,     // the base int to learn this skill
                        "max_skill":    30      // the maximum level you can learn
                ]) );
        }
}
