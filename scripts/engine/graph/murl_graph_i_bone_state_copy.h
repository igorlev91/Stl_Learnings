// Copyright 2010-2012 Spraylight GmbH

#ifndef __MURL_GRAPH_I_BONE_STATE_COPY_H__
#define __MURL_GRAPH_I_BONE_STATE_COPY_H__

#include "murl_graph_i_generic_node_target.h"
#include "murl_graph_i_state_unit.h"

namespace Murl
{
    namespace Graph
    {
        /**
         * @ingroup MurlGraphNodeInterfaces
         * @interface IBoneStateCopy
         * @brief The IBoneStateCopy graph node interface.
         * Nodes implementing this interface provide a means to copy the current bone
         * state assignment (performed via an IBoneState node) at a given source unit
         * to a given destination unit.
         *
         * See Graph::IBoneState for additional details.
         */
        class IBoneStateCopy : public IStateUnit
        {
        public:
            /**
             * @brief Get the mutable Graph::INode interface.
             * This method returns a mutable pointer to the node's Graph::INode interface, to
             * be able to query or modify common node properties such as active state,
             * visibility or ID.
             * @return The mutable Graph::INode interface, or null if not available
             */
            virtual INode* GetNodeInterface() = 0;
            /**
             * @brief Get the constant Graph::INode interface.
             * This method returns a constant pointer to the node's Graph::INode interface, to
             * be able to query common node properties such as active state, visibility
             * or ID.
             * @return The constant Graph::INode interface, or null if not available
             */
            virtual const INode* GetNodeInterface() const = 0;

            /**
             * @brief Set the source unit to copy the state assignment from.
             * @param unit The source unit, from 0 to IEnums::NUM_BONE_UNITS-1.
             * @return true if successful.
             */
            virtual Bool SetSourceUnit(UInt32 unit) = 0;
            /**
             * @brief Get the source unit to copy the state assignment from.
             * @return The source unit, from 0 to IEnums::NUM_BONE_UNITS-1.
             */
            virtual UInt32 GetSourceUnit() const = 0;
            
        protected:
            virtual ~IBoneStateCopy() {}
        };
        
        /**
         * @ingroup MurlGraphTargetInterfaces
         * @brief A container for referencing one or more Graph::IBoneStateCopy nodes.
         */
        typedef IGenericNodeTarget<IBoneStateCopy> IBoneStateCopyNodeTarget;
    }
}

#endif // __MURL_GRAPH_I_BONE_STATE_COPY_H__
