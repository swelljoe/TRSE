/*
 * Turbo Rascal Syntax error, “;” expected but “BEGIN” (TRSE, Turbo Rascal SE)
 * 8 bit software development IDE for the Commodore 64
 * Copyright (C) 2018  Nicolaas Ervik Groeneboom (nicolaas.groeneboom@gmail.com)
 *
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program (LICENSE.txt).
 *   If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef NODEPROGRAM_H
#define NODEPROGRAM_H


#include "source/Compiler/token.h"
#include "source/Compiler/pvar.h"
#include "source/Compiler/symboltable.h"
#include "source/Compiler/errorhandler.h"
#include "source/Compiler/ast/node.h"
#include "source/Compiler/ast/nodebuiltinmethod.h"
#include "source/Compiler/ast/nodeblock.h"
#include "source/Compiler/ast/nodeproceduredecl.h"
#include "source/Compiler/codegen/abstractcodegen.h"

class NodeProgram : public Node {
public:
    QString m_name, m_param;
    QStringList m_initJumps;
    QSharedPointer<NodeBlock> m_NodeBlock;
    NodeProgram(QString n, QString p, QSharedPointer<NodeBlock> b):Node() {
        m_NodeBlock = b;
        m_name = n;
        m_param = p;
    }

    void parseConstants(QSharedPointer<SymbolTable>  symTab) override {
        if (m_NodeBlock!=nullptr)
            m_NodeBlock->parseConstants(symTab);
    }




    void ExecuteSym(QSharedPointer<SymbolTable>  symTab) override;


    void Accept(AbstractCodeGen* dispatcher) override;

};

#endif // NODEPROGRAM_H
